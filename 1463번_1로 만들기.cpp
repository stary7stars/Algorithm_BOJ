#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF (987654321)
int dp[1000002];

int dfs(int n)
{	if (n == 1) return 0;
	
	int &ret = dp[n];
	if (ret != -1) return ret;
	
	int a, b, c;
	
	if (!(n % 3)) 
		a = dfs(n/3) + 1;
	else 
		a = INF;
	
	if (!(n & 1)) 
		b = dfs(n>>1) + 1;
	else 
		b = INF;
	
	c = dfs(n-1) + 1;
	
	return ret = min(min(a, b), c);
}

int main()
{
	int N;
	scanf("%d", &N);
	
	memset(dp, -1, sizeof(dp));
	
	printf("%d\n", dfs(N));
	
	return 0;
}
