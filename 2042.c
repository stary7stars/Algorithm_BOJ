// 구간합 
#include <stdio.h>

int N, M, K;
int Tcnt;
long long Tree[4000000];

void update(int idx, int data);
long long search(int s, int e);

int main(void)
{
    int i;

    scanf("%d %d %d", &N, &M, &K);
    M += K;
    for (Tcnt = 1; Tcnt < N; Tcnt *= 2);
    for (i = Tcnt; i < Tcnt + N; i++) scanf("%lld", &Tree[i]);
    for (i = Tcnt - 1; i >= 1; i--) 
    {
        Tree[i] = Tree[i * 2] + Tree[i * 2 + 1];
    }
    for (i = 0; i < M; i++)
    {
        int tmp, a, b;
        scanf("%d %d %d", &tmp, &a, &b);
        if (tmp == 1) update(a, b);
        else printf("%lld\n", search(a, b));
    }
}

void update(int idx, int data)
{
    idx = idx + Tcnt - 1;
    Tree[idx] = data;

    while (idx > 1)
    {
        idx /= 2;
        Tree[idx] = Tree[idx * 2] + Tree[idx * 2 + 1];
    }
}

long long search(int s, int e)
{
    long long res = 0;
    s = s + Tcnt - 1;
    e = e + Tcnt - 1;

    while (s <= e)
    {
        if (s & 1) res += Tree[s++];
        if (!(e & 1)) res += Tree[e--];
        s /= 2; e /= 2;
    } 

    return res;
}
