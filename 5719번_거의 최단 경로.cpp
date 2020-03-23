#include <iostream>
#include <queue>
using namespace std;

#define INF (987654321)
typedef pair<int, int> PII;

int d[502];
int injub[502][502];
vector<PII> edges[502];
vector<int> path[502];

void Dijkstra(int S, int D)
{
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, S});
	d[S] = 0;

	while (!pq.empty())
	{
		PII now = pq.top(); pq.pop();
		int cur = now.second;

		for (PII out : edges[cur])
		{
			int tmp = d[cur] + out.first;
			if ((injub[cur][out.second] != 0) && (d[out.second] >= tmp))
			{
				pq.push({tmp, out.second});
				d[out.second] = tmp;
			}
		}
	}
}

void erase(int S, int D)
{
	queue<int> q;
	q.push(D);
	
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		for (int prev : path[now])
		{
			if (d[now] == injub[prev][now] + d[prev])
			{
				injub[prev][now] = 0;
				q.push(prev);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (true)
	{
		int N, M, S, D, u, v, p;
		
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		
		for (int n = 0; n < N; n++)
		{
			edges[n].clear();
			path[n].clear();
			d[n] = INF;
			for (int k = 0; k < N; k++)
				injub[n][k] = 0;
		}
		
		for (int m = 0; m < M; m++)
		{
			cin >> u >> v >> p;
			edges[u].push_back({p, v});
			path[v].push_back(u);
			injub[u][v] = p;
		}
		
		Dijkstra(S, D);
		
		erase(S, D);
		
		for (int n = 0; n < N; n++)
			d[n] = INF;
			
		Dijkstra(S, D);
		
		if (d[D] == INF) cout << "-1\n";
		else cout << d[D] << '\n';
	}
	
	return 0;
}
