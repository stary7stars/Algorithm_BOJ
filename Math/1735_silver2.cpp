// 1735번 : 분수 합
#define SWAP(a, b) (tmp = a, a = b, b = tmp)
int GCD(int a, int b);
int LCM(int a, int b);

int main(void)
{
	int s;
	int s1, s2, m1, m2;
	int lcm, gcd;

	scanf("%d %d %d %d", &s1, &m1, &s2, &m2);

	lcm = LCM(m1, m2);
	s = (s1 * (lcm / m1)) + (s2 * (lcm / m2));
	gcd = GCD(s, lcm);
	s /= gcd;
	lcm /= gcd;

	printf("%d %d", s, lcm);

	return 0;
}

int GCD(int a, int b)
{
	int tmp;
	int r;
	
	if (a > b) SWAP(a, b);

	while (a)
	{
		r = b % a;
		b = a;
		a = r;
	}

	return b;
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}