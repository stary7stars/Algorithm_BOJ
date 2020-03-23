#include <iostream>
#include <queue>
using namespace std;

#define INF (987654321)
typedef pair<int, int> PII;

int d[1002];
vector<PII> edges[1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M, a, b, c, s, e;
	cin >> N >> M;
	
	for (int n = 1; n <= N; n++)
		d[n] = INF;
	
	for (int m = 0; m < M; m++)
	{
		cin >> a >> b >> c;
		edges[a].push_back({c, b});
	}
	
	cin >> s >> e;
	
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, s});
	d[s] = 0;
	
	while (!pq.empty())
	{
		PII now = pq.top(); pq.pop();
		if (now.second == e) break;
		if (d[now.second] < now.first) continue;

		for (PII out : edges[now.second])
		{
			int tmp = d[now.second] + out.first;
			if (d[out.second] > tmp)
			{
				pq.push({tmp, out.second});
				d[out.second] = tmp;
			}
		}
	}
	
	cout << d[e] << '\n';
	
	return 0;
}
