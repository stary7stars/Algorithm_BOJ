// 1806번 : 부분합
#include <iostream>
using namespace std;

#define MIN(a, b) (((a)<(b))?(a):(b))
int Num[100100];

int main()
{
    ios::sync_with_stdio(false);

    int n, s;
    int left, right, sum, ans = 100001;

    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> Num[i];
    sum = Num[1];
    for (left = 1, right = 1; left <= right && right <= n;  )
    {
        if (sum < s) sum += Num[++right];
        else
        {
            ans = MIN(ans, (right - left + 1));
            sum -= Num[left++];
        }
    }
    if (ans == 100001) ans = 0;
    cout << ans << endl;
    return 0;
}
