// 타임머신
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> IP;
IP edges[6001];
int d[501];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int n = 1; n <= N; n++) {
        d[n] = 987654321;
    }

    for (int n = 1; n <= M; n++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[n] = IP(c, P(a, b));
    }

    d[1] = 0;
    for (int n = 1; n < N; n++) {
        for (int e = 1; e <= M; e++) {
            int x = edges[e].second.first;
            int y = edges[e].second.second;
            int cost = edges[e].first;
            if (d[x] == 987654321) continue;
            if (d[y] > d[x] + cost) {
                d[y] = d[x] + cost;
            }
        }
    }    

    int e;
    for (e = 1; e <= M; e++) {
        int x = edges[e].second.first;
        int y = edges[e].second.second;
        int cost = edges[e].first;
        if (d[x] == 987654321) continue;
        if (d[y] > d[x] + cost) {
            break;
        }
    }
    if (e <= M) {
        printf("-1\n");
    }
    else {
        for (int n = 2; n <= N; n++) {
            if (d[n] == 987654321) printf("-1\n");
            else printf("%d\n", d[n]);
        }
    }

    return 0;
}