// 네트워크 연결
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct _st
{
	int s, e, c;
}Edge;
Edge edges[100010];
int parent[1010];
bool compare(Edge a, Edge b) { return a.c < b.c; }

int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b, c;
	int cost = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edges[i] = { a, b, c };
	}
	sort(edges, edges + m, compare);
	for (int i = 0; i < m; i++)
	{
		int s = edges[i].s;
		int e = edges[i].e;
		if (find(s) == find(e)) continue;
		parent[find(s)] = find(e);
		cost += edges[i].c;
	}

	cout << cost << '\n';

	return 0;
}
