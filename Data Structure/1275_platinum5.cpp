// 1275¹ø: Ä¿ÇÇ¼ó2
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
using namespace std;

#define SWAP(x, y) {int tmp = x; x = y; y = tmp;}
typedef long long ll;
int N, Q;
ll * tree;

void update(int x, ll val) 
{
    while (x <= N) {
        tree[x] += val;
        x += (x&-x);
    }
}

ll query(int x) 
{
    ll ret = 0ll;
    while (x > 0) {
        ret += tree[x];
        x -= (x&-x);
    }

    return ret;
}

int main()
{
    scanf("%d %d", &N, &Q);
    tree = new ll[N+1];
    for (int n = 1; n <= N; n++) {
        ll a;
        scanf("%lld", &a);
        update(n, a);
    }
    
    for (int q = 0; q < Q; q++) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if (x > y) SWAP(x, y);
        printf("%lld\n", query(y) - query(x-1));
        update(a, b-(query(a) - query(a-1)));
    }

    return 0;
}