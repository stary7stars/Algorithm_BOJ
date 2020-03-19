//1647번: 도시 분할 계획
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> PIPII;

int p[100002];
PIPII edges[1000002]; 

int find(int a)
{
	if (p[a] == a) return a;
	else return p[a] = find(p[a]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M, a, b, c;
	int sum = 0, cnt = 0;
	cin >> N >> M;
	for (int n = 1; n <= N; n++)
		p[n] = n;
	for (int m = 0; m < M; m++)
	{
		cin >> a >> b >> c;
		edges[m] = {c, {a, b}};
	}
	
	sort(edges, edges + M);
	
	for (int m = 0; m < M; m++)
	{
		a = edges[m].second.first;
		b = edges[m].second.second;
		c = edges[m].first;
		
		if (find(a) != find(b))
		{
			p[find(b)] = p[find(a)];
			sum += c;
			if (++cnt == N-1) 
			{
				sum -= c;
				break;	
			}
		}
	}
	
	cout << sum << '\n';
	
	return 0;
}
