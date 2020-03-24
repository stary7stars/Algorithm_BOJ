#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int map[1002][3];
int dp[1002][3];

int dfs(int d, int idx)
{
	if (d == 1) return dp[d][idx];
	
	int &ret = dp[d][idx];
	if (ret != -1) return ret;
	return ret = min(dfs(d - 1, ((idx + 1) % 3)), dfs(d - 1, ((idx + 2) % 3))) + map[d][idx];	
}
int main()
{
	int N;
	scanf("%d", &N);
	
	for (int n = 1; n <= N; n++)
		scanf("%d %d %d", &map[n][0], &map[n][1], &map[n][2]);
		
	memset(dp, -1, sizeof(dp));
	dp[1][0] = map[1][0];
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
	
	printf("%d\n", min(min(dfs(N, 0), dfs(N, 1)), dfs(N, 2)));
		
	return 0;
}
