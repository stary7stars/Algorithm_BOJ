// 2169번 : 로봇 조종하기
#include <iostream>
#include <algorithm>
using namespace std;

#define INF (987654321)
int map[1002][1002];
int dp[1002][1002];
int tmp[2][1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;	
	cin >> N >> M;
	
	for (int n = 1; n <= N ; n++)
		for (int m = 1; m <= M; m++)
			cin >> map[n][m];
	
	for (int c = 1; c <= M; c++)
		dp[1][c] = dp[1][c-1] + map[1][c];
	
	for (int r = 1; r <= N; r++)
		dp[r][1] = dp[r-1][1] + map[r][1];
	
	for (int r = 2; r <= N; r++)
	{	
		tmp[0][0] = dp[r-1][1];
		for (int c = 1; c <= M; c++)
			tmp[0][c] = max(tmp[0][c-1], dp[r-1][c]) + map[r][c];
		
		tmp[1][M+1] = dp[r-1][M];
		for (int c = M; c >= 1; c--)
			tmp[1][c] = max(tmp[1][c+1], dp[r-1][c]) + map[r][c];
		
		for (int c = 1; c <= M; c++)
			dp[r][c] = max(tmp[0][c], tmp[1][c]);
	}
	
	cout << dp[N][M] << '\n';
	
	return 0;
}
