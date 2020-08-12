// 1644번 : 소수의 연속합
#include <stdio.h>

bool num[4000010];
int sosu[4000010];

int main()
{
	int N, cnt = 0, sum = 0, ans = 0;
	scanf("%d", &N);
	
	sosu[cnt++] = 2;
	for (int i = 3; i * i <= N; i += 2)
	{
		if (num[i]) continue;
		for (int j = i * i; j <= N; j += i)
			num[j] = true;				
	}		
	
	for (int i = 3; i <= N; i += 2) 
		if (!num[i]) 
			sosu[cnt++] = i;
	
	for (int s = 0, e = 0; s < cnt;)
	{
		if (sum == N) 
		{
			ans++;
			sum -= sosu[s++];
		}
		else if (sum < N)
            if (e < cnt)
				sum += sosu[e++];
			else break;
		else
			sum -= sosu[s++];
	}
	
	printf("%d\n", ans);
	return 0;
}