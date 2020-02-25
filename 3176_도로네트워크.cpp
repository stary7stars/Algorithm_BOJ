// 도로 네트워크
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
vector<pii> edges[100010];
int d[100010];
int bi[20];
int p[20][100010];
int so[20][100010];
int de[20][100010];

void depth()
{
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        for (pii next : edges[now])
        {
            if (d[next.first] == -1)
            {
                d[next.first] = d[now] + 1;
                p[0][next.first] = now;
                so[0][next.first] = next.second;
                de[0][next.first] = next.second;
                q.push(next.first);
            }
        }
    }
}

void lca(int a, int b)
{
    int ans_min = 987654321, ans_max = -1;

    if (d[a] != d[b])
    {
        int diff;
        
        if (d[a] < d[b]) { int tmp = a; a = b; b = tmp; }
        diff = d[a] - d[b];

        for (int i = 19; i >= 0; i--)
        {
            if (diff >= bi[i])
            {
                diff -= bi[i];
                ans_min = min(ans_min, so[i][a]);
                ans_max = max(ans_max, de[i][a]);
                a = p[i][a];
            }
        }
    }

    if (a == b)
    {
        cout << ans_min << ' ' << ans_max << '\n';
        return;
    }

    for (int i = 19; i >= 0; i--)
    {
        if (d[a] >= bi[i])
        {
            if (p[i][a] != p[i][b])
            {
                ans_min = min(ans_min, min(so[i][a], so[i][b]));
                ans_max = max(ans_max, max(de[i][a], de[i][b]));
                a = p[i][a];
                b = p[i][b];
            }
        }
    }

    ans_min = min(ans_min, min(so[0][a], so[0][b]));
    ans_max = max(ans_max, max(de[0][a], de[0][b]));
    cout << ans_min << ' ' << ans_max << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    int a, b, c;
    
    bi[0] = 1;
    for (int b = 1; b <= 19; b++) 
        bi[b] = (bi[b - 1] << 1);

    cin >> N;
    for (int n = 1; n <= N - 1; n++)
    {
        cin >> a >> b >> c;
        edges[a].push_back(pii(b, c));
        edges[b].push_back(pii(a, c));
        d[n] = -1;
    }
    d[N] = -1;

    depth();
    p[0][1] = 1;
    for (int v = 1; v <= 19; v++)
    {
        for (int n = 1; n <= N; n++)
        {
            p[v][n] = p[v-1][ p[v-1][n] ];
            so[v][n] = min(so[v-1][n], so[v-1][ p[v-1][n] ]);
            de[v][n] = max(de[v-1][n], de[v-1][ p[v-1][n] ]);
        }
    }
    
    cin >> K;
    for (int k = 1; k <= K; k++)
    {
        cin >> a >> b;
        lca(a, b);
    }

    return 0;
}
