//9372번: 상근이의 여행
#include <iostream>
using namespace std;
typedef pair<int, int> PII;

int p[1002];
PII edges[10002];

int find(int a)
{
	if (p[a] == a) return a;
	else return p[a] = find(p[a]);
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while (TC--)
	{
		int N, M, a, b;
		int cnt = 0;
		cin >> N >> M;
		
		for (int n = 1; n <= N; n++)
			p[n] = n;
		for (int m = 0; m < M; m++)
		{
			cin >> a >> b;
			edges[m] = {a, b};
			if (find(a) != find(b))
			{
				p[find(b)] = p[find(a)];
				cnt++;
			}
		}
	
		cout << cnt << '\n';
	}
	
	return 0;
}
