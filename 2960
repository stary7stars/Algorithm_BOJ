// 에라토스테네스의 체
#include <iostream>
using namespace std;

int Num[1010];

int main()
{
    ios::sync_with_stdio(false);

    int n, k;
    int cnt = 0;
    int flag = 0;
    int ans = 0;

    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        if (Num[i] == 0)
        {
            cnt++;
            if (cnt == k) { ans = i; break; }
            for (int j = i * 2; j <= n; j += i)
            {
                if (Num[j] == 1) continue;
                Num[j] = 1;
                if (++cnt == k) 
                {   
                    flag = 1;
                    ans = j;
                    break;
                }       
            }
        }
        if (flag) break;
    }

    cout << ans << endl;

    return 0;    
}
