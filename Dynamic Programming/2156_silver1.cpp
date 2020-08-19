//2156번 : 포도주 시식
#include <stdio.h>
#include <algorithm>
using namespace std;

int map[10002];
int dp[10002];

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int n = 1; n <= N; n++)
		scanf("%d", &map[n]); 
		
	dp[1] = map[1];
	dp[2] = map[1] + map[2];
	for (int n = 3; n <= N; n++)
		dp[n] = max(max(dp[n-3] + map[n-1], dp[n-2]) + map[n], dp[n-1]);
	
	printf("%d\n", dp[N]);
	
	return 0;
}
