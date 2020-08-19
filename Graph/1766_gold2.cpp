// 1766번 : 문제집
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int indegree[32002];
vector<int> v[32002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M, a, b;
	cin >> N >> M;
	
	for (int m = 0; m < M; m++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int n = 1; n <= N; n++)
	{
		if (indegree[n] == 0) 
			pq.push(n);
	}
	
	while (!pq.empty())
	{
		int now = pq.top(); pq.pop();
		cout << now << ' ';
		indegree[now] == -1;
		for (int out : v[now])
			if (--indegree[out] == 0) pq.push(out);
	}
	
	cout << '\n';
	
	return 0;
}
