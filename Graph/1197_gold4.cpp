// 1197번: 최소 스패닝 트리
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> PIIPI;

int p[10002];
PIIPI edges[10002];

int find(int a)
{
	if (p[a] == a) return a;
	else return p[a] = find(p[a]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int V, E, a, b, c;
	int Min = 2147483648;
	int cnt = 0, sum = 0;
	cin >> V >> E;
	
	for (int v = 1; v <= V; v++)
		p[v] = v;
		
	for (int e = 0; e < E; e++)
	{
		cin >> a >> b >> c;
		edges[e] =  { c, {a, b} };
	}
	
	sort(edges, edges+E);
	
	for (int e = 0; e < E; e++)
	{
		a = edges[e].second.first;
		b = edges[e].second.second;
		c = edges[e].first;
		
		if (find(a) != find(b))
		{
			p[find(b)] = p[find(a)];
			sum += c;
			cnt++;
		}
		
		if (cnt == V-1) break;
	}
	
	cout << sum << '\n';
	return 0;
}
