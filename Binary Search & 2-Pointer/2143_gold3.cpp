// 2143번: 두 배열의 합
#include <stdio.h>

int arr[10010];

int main()
{
	int N, M, s = 0, e = 0, sum = 0, cnt = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	while (s < N)
	{
		if (sum == M)
		{
			cnt++;
			sum -= arr[s++];
		}
		else if (sum < M) 
			if (e < N)
				sum += arr[e++];
			else break;
		else
			sum -= arr[s++];

		if (e < s) e = s;
	}

	printf("%d\n", cnt);
}