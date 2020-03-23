#include <iostream>
using namespace std;

int map[502][502], dp[502][502];
int N, Max;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int n = 1; n <= N; n++)
		for (int k = 1; k <= n; k++)
			cin >> map[n][k];
	
	for (int n = 1; n <= N; n++)
	{
		dp[n][1] = dp[n-1][1] + map[n][1];
		dp[n][n] = dp[n-1][n-1] + map[n][n];	 
	}
	
	for (int n = 3; n <= N; n++)
		for (int k = 2; k < N; k++)
			dp[n][k] = max(dp[n-1][k-1], dp[n-1][k]) + map[n][k];
			
	Max = dp[N][1];
	for (int n = 2; n <= N; n++)
		if (dp[N][n] > Max) Max = dp[N][n];

	cout << Max << '\n';
	
	return 0;
}
