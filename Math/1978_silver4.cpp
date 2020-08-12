#include <stdio.h>

int Check_Sosu(int n);
int main(void)
{
	int i;
	int n;
	int num;
	int cnt = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (Check_Sosu(num)) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}

int Check_Sosu(int n)
{
	int i;
	int h;

	if (n == 1) return 0;
	if (n == 2) return 1;
	if (!(n & 0x1)) return 0;

	h = n >> 1;
	for (i = 3; i <= h; i += 2)
	{
		if ((n % i) == 0) return 0;
	}

	return 1;
}