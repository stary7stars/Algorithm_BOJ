// 1920번 : 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;

int num[100002];

int bs(int s, int e, int k)
{
	int m;
	
	while (s < e)
	{
		m =  (s + e) >> 1;
		if (num[m] == k) return m;
		else if (num[m] > k) e = m;
		else s = m + 1;
	}	

	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K;
	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> num[n];
	
	sort(num, num + N);
	
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> K;
		if (num[bs(0, N, K)] == K) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}