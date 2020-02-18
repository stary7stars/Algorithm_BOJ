// 키 순서
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int injub[505][505];
int visit[505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
  
	int n, m;
	int a, b;
	int ans = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		injub[a][b] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		queue<int> q;
		queue<int> backq;
		q.push(i);
		backq.push(i);

		while (!q.empty())
		{
			int now = q.front(); q.pop();
			for (int j = 1; j <= n; j++)
				if (visit[j] != i && injub[now][j] == 1)
				{
					q.push(j); visit[j] = i; cnt++;
				}
		}

		while (!backq.empty())
		{
			int now = backq.front(); backq.pop();
			for (int j = 1; j <= n; j++)
				if (visit[j] != i && injub[j][now] == 1)
				{
					backq.push(j); visit[j] = i; cnt++;
				}
		}

		if (cnt == n - 1) ans++;
	}

	cout << ans << '\n';
	return 0;
}
