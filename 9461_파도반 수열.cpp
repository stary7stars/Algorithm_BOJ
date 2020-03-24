#include <stdio.h>

int main()
{
	int TC;
	long long f[101] = { 0ll };
	scanf("%d", &TC);
	f[1] = f[2] = f[3] = 1ll;
	f[4] = 2ll; 
	for (int i = 5; i < 101; i++)
		f[i] = f[i-1] + f[i-5];
		
	while (TC--)
	{ 
		int N;
		scanf("%d", &N);	
		printf("%lld\n", f[N]);
	}
	
	return 0;
}
