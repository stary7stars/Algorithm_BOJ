//영화 수집
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string.h>
using namespace std;

int N, M;
int tree[200002];
int ptr[100001];

void update(int x, int val, int last) 
{
    while (x <= last) {
        tree[x] += val;
        x += (x&-x);
    }
}

int query(int x)
{
    int ret = 0;

    while (x > 0) {
        ret += tree[x];
        x -= (x&-x);
    }

    return ret;
}

int main() 
{
    int TC;
    scanf("%d", &TC);
    for (int t = 0; t < TC ; t++) {
        scanf("%d %d", &N, &M);
        int last = N;
        memset(tree, 0, sizeof(int) * (N + M + 1));
        for (int n = 1; n <= N; n++) {
            update(n, 1, N+M+1);
            ptr[n] = N - n + 1;
        }

        for (int m = 0; m < M; m++) {
            int a;
            scanf("%d", &a);
            printf("%d ", N-query(ptr[a]));
            update(ptr[a], -1, N+M+1);
            ptr[a] = ++last;
            update(ptr[a], 1, N+M+1);
        }
        printf("\n");
    }
    return 0;
}