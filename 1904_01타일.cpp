#include <stdio.h>

int main()
{
	int N;
	int f[2] = { 2, 1 };
	scanf("%d", &N);
	
	for (int n = 3; n <= N; n++)
		f[n & 1] = (f[0] + f[1]) % 15746;
		
	printf("%d\n", f[N & 1]);
	
	return 0;
}
