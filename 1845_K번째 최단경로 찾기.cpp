#include <iostream>
#include <queue>
using namespace std;

#define INF (987654321)
typedef pair<int, int> PII;

priority_queue<int, vector<int>, less<int>> d[1002];
vector<PII> edges[1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K, a, b, c, cnt = 0;
	cin >> N >> M >> K;
		
	for (int m = 0; m < M; m++)
	{
		cin >> a >> b >> c;
		edges[a].push_back({c, b});
	}
	
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, 1});
	d[1].push(0);
	
	while (!pq.empty())
	{
		PII now = pq.top(); pq.pop();
		int cur = now.second;
		int cost = now.first;
		
		for (PII out : edges[cur])
		{
			int tmp = cost + out.first;
			if (d[out.second].size() < K)
			{
				d[out.second].push(tmp);
				pq.push({tmp, out.second});
			}
			else if (d[out.second].top() > tmp)
			{
				d[out.second].pop();
				d[out.second].push(tmp);
				pq.push({tmp, out.second});
			}
		}
	}
	
	for (int n = 1; n <= N; n++)
	{
		if (d[n].size() == K) cout << d[n].top() << '\n';
		else cout << -1 << '\n';
	}
	
	return 0;
}
