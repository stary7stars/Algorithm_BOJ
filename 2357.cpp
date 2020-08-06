// ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
using namespace std;

int N, M, idx;
int tree_min[500001];
int tree_max[500001];
int arr[100001];

int getMax(int x, int y)
{
    return (x > y) ? x : y;
}

int getMin(int x, int y) 
{
    return (x < y) ? x : y;
}

int update(int arr[], int tree[], int x, int s, int e, int comp(int, int)) 
{
    if (s == e) {
        return tree[x] = arr[s];
    }

    int mid = (s+e) / 2;
    int val1 = update(arr, tree, x*2, s, mid, comp);
    int val2 = update(arr, tree, (x*2)+1, mid+1, e, comp);
    tree[x] = comp(val1, val2);
    return tree[x];
}

int query(int tree[], int now, int s, int e, int x, int y, int comp(int, int), int ret)
{
    if (x > e || y < s) {
        return ret;
    }
    if (x <= s && e <= y) {
        return tree[now];
    }

    int mid = (s+e) / 2;
    int val1 = query(tree, now*2, s, mid, x, y, comp, ret);
    int val2 = query(tree, (now*2)+1, mid+1, e, x, y, comp, ret);

    return comp(val1, val2);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++ ) {
        scanf("%d", &arr[i]);
    }
    update(arr, tree_min, 1, 1, N, getMin);
    update(arr, tree_max, 1, 1, N, getMax);

    for (int m = 0; m < M; m++) {
        int a, b; 
        scanf("%d %d", &a, &b);
        printf("%d %d\n", 
                query(tree_min, 1, 1, N, a, b, getMin, 1000000001),
                query(tree_max, 1, 1, N, a, b, getMax, 0));
    }
    return 0;
}