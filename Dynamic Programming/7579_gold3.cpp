#include <iostream>
#include <string.h>
using namespace std;

int N, M, Tot;
int mem[102], cost[102];
int dp[10002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	for (int n = 1; n <= N; n++)
	 	cin >> mem[n];
	for (int n = 1; n <= N; n++)
	{
		cin >> cost[n];
		Tot += cost[n];
	}
	memset(dp, -1, sizeof(dp));
	
	dp[0] = 0;
	for (int n = 1; n <= N; n++)
	{
		int tmp = cost[n];
		for (int c = Tot; c >= tmp; c--)
		{
			if (dp[c-tmp] == -1) continue;
			dp[c] = max(dp[c], dp[c-tmp] + mem[n]);
		}
	}
	
	for (int c = 0; c <= Tot; c++)
	{
		if (dp[c] != -1 && dp[c] >= M)
		{
			cout << c << '\n';
			break;
		}
	}
	
	return 0;
}
