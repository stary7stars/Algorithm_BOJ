#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> buha[100002];
int in[100002];
int out[100002];
int tree[100002];

void update(int x, int val)
{
    while (x <= N) {
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

void DFS(int x)
{
    in[x] = ++cnt;
    for (int c : buha[x]){
        DFS(c);
    }
    out[x] = cnt;
}

int main()
{
    scanf("%d %d", &N, &M);
    int tmp; scanf("%d", &tmp);
    for (int n = 2; n <= N; n++) {
        int a;
        scanf("%d", &a);
        buha[a].push_back(n);
    }

    DFS(1);

    for (int m = 0; m < M; m++) {
        int a, b, c; scanf("%d", &a);
        if ((a & 1) == 1) {
            // 구간 업데이트
            scanf("%d %d", &b, &c);
            update(in[b], c);
            update(out[b]+1, -c);
        }
        else {
            // 포인트 쿼리
            scanf("%d", &b);
            printf("%d\n", query(in[b]));
        }
    }
    
    return 0;
}
