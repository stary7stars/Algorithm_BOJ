// 1516번 : 게임 개발
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> build[505];
queue<int> q;
int tm[505];
int in[505];
int ans[505];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, a;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> tm[i];
		while (true)
		{
			cin >> a;
			if (a == -1) break;
			build[a].push_back(i);
			in[i]++;
		}
		ans[i] = -1;
	}

	for (int n = 1; n <= N; n++)
		if (in[n] == 0) { q.push(n); ans[n] = tm[n]; }

	while (!q.empty())
	{
		int now = q.front(); q.pop();
		for (int next : build[now])
		{
			if (ans[next] < ans[now] + tm[next])
				ans[next] = ans[now] + tm[next];
			if (--in[next] == 0 )
				q.push(next);
		}
	}

	for (int n = 1; n <= N; n++)
		cout << ans[n] << '\n';

	return 0;
}
