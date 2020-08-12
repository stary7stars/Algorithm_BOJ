#include <iostream>
#include <algorithm>
using namespace std;

int map[302], dp[2][302];
int N; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int n = 1; n <= N; n++)
		cin >> map[n];
	
	dp[0][1] = map[1];
	dp[0][2] = map[2];
	
	for (int i = 1; i <= N - 1; i++)
	{
		dp[0][i+2] = max (dp[0][i], dp[1][i]) + map[i+2];
		dp[1][i+1] = dp[0][i] + map[i+1];
	}
	
	cout << max(dp[0][N], dp[1][N]) << '\n';
	
	return 0;
}
