// 1976번 : 여행가자
#include <iostream>
using namespace std;

int injub[202][202];
int p[202];
int trip[1002];

int find(int n)
{
	if (p[n] == n) return n;
	else return p[n] = find(p[n]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	bool flag = true;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) p[i] = i;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> injub[i][j];
			if ((j > i) && (injub[i][j] == 1)) 
				p[find(j)] = p[find(i)];
		}
	}
		
	for (int i = 1; i <= N; i++)
		p[i] = find(i);
		
	for (int m = 0; m < M; m++)
		cin >> trip[m];
	
	int s = p[trip[0]];
	for (int m = 1; m < M; m++)
		if (p[trip[m]] != s) { flag = false; break; }
		
	if (flag) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}