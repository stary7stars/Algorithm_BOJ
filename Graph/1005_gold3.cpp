// 1005踰�∏: ACM Craft 
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
int t[1002];
int acctime[1002];
int indegree[1002];
vector<int> v[1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while (TC--)
	{
		int N, K, W, a, b;
		cin >> N >> K;
		
		for (int n = 1; n <= N; n++)
		{
			cin >> t[n];
			indegree[n] = acctime[n] = 0;
			v[n].clear();
		}	
		for (int k = 0; k < K; k++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			indegree[b]++;
		}
		
		cin >> W;
		
		queue<int> q;

		for (int n = 1; n <= N; n++)
			if (indegree[n] == 0) { q.push(n); acctime[n] = 0; }
		
		while (!q.empty())
		{
			int now = q.front(); q.pop();
			if (now == W) break;
			for (int out : v[now])
			{
				if (acctime[out] < acctime[now] + t[now])
					acctime[out] = acctime[now] + t[now];
				if (--indegree[out] == 0) 
					q.push(out);
			}
		}
		
		cout << acctime[W] + t[W] << '\n';
	} 
	return 0;
}
