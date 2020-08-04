#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX (1000000001)
int tree[265000];

int query(int x, int y) 
{
    int ret = MAX;
    while (x < y) {
        if ((x & 1) == 1) {
            ret = min(tree[x], ret);
            x++;
        }

        if ((y & 1) == 0) {
            ret = min(tree[y], ret);
            y--;
        }
        x >>= 1; y >>= 1;
    }

    if (x == y)
        ret = min(ret, tree[x]);
    return ret;
}

int main()
{
    int N, M, idx;
    scanf("%d %d", &N, &M);
    for (idx = 1; idx < N; idx <<= 1);

    for (int n = idx; n < idx + N; n++) {
        scanf("%d", &tree[n]);
    }

    for (int n = idx + N; n < (idx << 1); n++) {
        tree[n] = MAX;
    }

    for (int n = idx-1; n > 0; n--) {
        tree[n] = min(tree[n<<1], tree[(n<<1)|1]);
    }

    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", query(idx + a - 1, idx + b - 1));
    }


    return 0;
}