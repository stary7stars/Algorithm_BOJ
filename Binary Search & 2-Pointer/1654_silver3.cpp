// 1654번 : 랜선 자르기
#include <stdio.h>
#include <algorithm>
using namespace std;

long long K, N, Max = -1ll, Len[10002];

long long bs(long long s, long long e)
{
	long long ans = 0ll;
	
	while (s <= e)
	{
		long long cnt = 0ll;
		long long m = (s + e) >> 1ll;
		for (int k = 1; k <= K; k++)
			cnt += (Len[k] / m);
		if (cnt >= N) { ans = max(ans, m); s = m + 1ll; }
		else e = m - 1ll;
	}
	
	return ans;
}

int main()
{
	scanf("%lld %lld", &K, &N);
	for (int k = 1; k <= K; k++)
	{
		scanf("%lld", &Len[k]);
		if (Len[k] > Max) Max = Len[k];
	}

	printf("%lld\n", bs(1ll, Max));
	
	return 0;
}