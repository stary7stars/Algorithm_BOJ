// LCA2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bi[19];
int p[20][100010];
int d[100010];
vector<int> edges[100010];

void depth()
{
	queue<pair<int,int>> q;
	d[1] = 0;
	q.push({ 1, 1 });
	while (!q.empty())
	{
		pair<int, int> now = q.front(); q.pop();

		for (int next : edges[now.first])
		{
			if (next != now.second)
			{
				d[next] = d[now.first] + 1;
				p[0][next] = now.first;
				q.push({ next, now.first });
			}
		}
	}
}

int lca(int a, int b)
{
	int diff;

	if (d[a] != d[b])
	{
		if (d[a] < d[b]) { int tmp = a; a = b; b = tmp; }
		diff = d[a] - d[b];

		for (int k = 18; k >= 0; k--)
		{
			if (diff >= bi[k]) { diff -= bi[k]; a = p[k][a]; }
			if (diff == 0) break;
		}
	}

	if (a == b) return a;

	for (int k = 18; k >= 0; k--)
		if (d[a] >= bi[k]) 
			if (p[k][a] != p[k][b]) { a = p[k][a]; b = p[k][b]; }

	return p[0][a];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b;
	
	cin >> N;
	
	for (int n = 0; n < N - 1; n++)
	{
		cin >> a >> b;
		
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bi[0] = 1;
	for (int b = 1; b <= 18; b++) bi[b] = (bi[b - 1] << 1);

	depth();

	for (int k = 1; k <= 18; k++)
		for (int n = 1; n <= N; n++)
			p[k][n] = p[k - 1][p[k - 1][n]];

	cin >> M;
	for (int m = 1; m <= M; m++)
	{
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}
