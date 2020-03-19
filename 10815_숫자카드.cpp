//10815번: 숫자카드 
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[500002];

bool bs(int a)
{
	int m, s = 0, e = N;
	
	while (s < e)
	{
		m = (s + e) >> 1;
		if (num[m] == a) return true;
		if (num[m] < a) s = m + 1;
		else e = m;
	}
	
	if (num[m] == a) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int M, a;
	
	cin >> N;
	for (int n = 0; n < N; n++)
		cin >> num[n];
	
	sort(num, num + N);
	
	cin >> M;
	for (int m = 0; m < M; m++)
	{
		cin >> a;
		if (bs(a)) cout << 1 << ' ';
		else cout << 0 << ' ';
	}
	
	return 0;
}
