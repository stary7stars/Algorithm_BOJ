// 2252번 : 줄 세우기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> edges[32010];
int in[32010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int a, b;

	cin >> N >> M;

	for (int m = 1; m <= M; m++)
	{
		cin >> a >> b;
		edges[a].push_back(b);
		in[b]++;
	}

	for (int n = 1; n <= N; n++)
		if (in[n] == 0) q.push(n);
	
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		cout << now << ' ';

		for (int next : edges[now])
			if (--in[next] == 0) q.push(next);
	}
	cout << '\n';
	return 0;
}
