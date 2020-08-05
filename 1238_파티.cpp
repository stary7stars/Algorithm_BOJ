#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> P;
int N, M, X;
vector<P> v1[1002];
vector<P> v2[1002];
int dijk1[1002];
int dijk2[1002];

void go(vector<P> v[], int dijk[])
{
    priority_queue< P, vector<P>, greater<P> > pq;
    dijk[X] = 0;
    for (P now : v[X]) {
        pq.push(now);
    }

    while (!pq.empty()) {
        P now = pq.top(); pq.pop();
        int cur = now.second;
        int cost = now.first; // 현재 노드가 갖고 있는 cur에 도착하는데 걸린 cost
        if (dijk[cur] < cost) continue;
        dijk[cur] = cost;
        for (P c : v[cur]) {
            if (cost + c.first < dijk[c.second]) {
                pq.push(P(cost + c.first, c.second));
            }
        }
    }
}


int main()
{
    scanf("%d %d %d", &N, &M, &X);
    for (int n = 1; n <= N; n++) {
        dijk1[n] = dijk2[n] = 987654321;
    }

    for (int m = 0;  m < M; m++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v1[a].push_back(P(c, b));
        v2[b].push_back(P(c, a));
    }

    go(v1, dijk1);
    go(v2, dijk2);

    int Max = -1;

    for (int n = 1; n <= N; n++) {
        printf("%d %d %d\n", n, dijk1[n], dijk2[n]);
        if (Max < dijk1[n] + dijk2[n])
            Max = dijk1[n] + dijk2[n];
    }

    printf("%d\n", Max);
    return 0;
}