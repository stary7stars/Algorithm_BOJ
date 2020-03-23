#include <stdio.h>

int main()
{
	int N;
	long long f[2] = {0, 1};
	scanf("%d", &N);
	
	for (int i = 2; i <= N; i++)
		f[i & 1] = f[0] + f[1];
	
	printf("%lld\n", f[N & 1]);
	
	return 0;
}
