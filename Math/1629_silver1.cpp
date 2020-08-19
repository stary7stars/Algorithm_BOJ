// 1629번 : 곱셈
#include <iostream>
using namespace std;
typedef long long lli;
lli c;

int gop(lli a, lli b)
{
	lli ret;
	if (b == 1) return a % c;
	if (b & 1)
	{
		ret = gop(a, (b - 1) / 2) % c;
		ret = ((ret * ret) % c) * a % c;
	}
	else
	{
		ret = gop(a, b / 2) % c;
		ret = (ret * ret) % c;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	lli a, b;
	cin >> a >> b >> c;
	if (a == 1 || b == 1) cout << a % c;
	else cout << gop(a, b) << '\n';

	return 0;
}