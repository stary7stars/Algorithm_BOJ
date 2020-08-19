// 1753번 : 최단경로
#include <iostream>
#include <queue>
using namespace std;

#define INF (987654321)
typedef pair<int, int> PII;

int d[20002]; 
vector<PII> edges[20002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int V, E, s;
	int a, b, c;
	cin >> V >> E >> s;
	
	for (int v = 1; v <= V; v++)
		d[v] = INF;
	
	for (int e = 0; e < E; e++)
	{
		cin >> a >> b >> c;
		edges[a].push_back({c, b});
	}
	
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	
	pq.push({0, s});
	d[s] = 0;
	
	while (!pq.empty())
	{
		PII now = pq.top(); pq.pop();
		if (now.first > d[now.second]) continue;
		
		for (PII out : edges[now.second])
		{
			if (d[out.second] > d[now.second] + out.first)
			{
				pq.push({d[now.second] + out.first, out.second});
				d[out.second] = d[now.second] + out.first;
			}
		}
	}

	for (int v = 1; v <= V; v++)
		if (d[v]==INF) cout <<  "INF\n";
		else cout << d[v] << '\n';
	
	return 0;
}
