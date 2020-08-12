// 1003번 : 피보나치 함수
#include <stdio.h>

int main()
{
	int TC, o[42], z[42];
	scanf("%d", &TC);
	
	o[0] = 0, o[1] = 1, o[2] = 1;
	z[0] = 1, z[1] = 0, z[2] = 1;
	
	for (int i = 3; i < 42; i++)
	{
		o[i] = o[i-1] + o[i-2];
		z[i] = z[i-1] + z[i-2];
	}
	
	while (TC--)
	{
		int N;
		scanf("%d", &N);
		
		printf("%d %d\n", z[N], o[N]); 
	}
	
	return 0;
}
