//골드바흐의 추측;
#include <iostream>
using namespace std;
bool Num[1000010];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    for (int i = 3; i < 1001; i+=2)
        if (!Num[i])
            for (int j = i * i; j < 1000001; j += i) Num[j] = true;
    while(true)
    {
        int i;
        bool flag = true;
        cin >> n;
        if (n == 0) break;
        for (i = 3; i <= (n >> 1); i += 2)
            if (!Num[i] && !Num[n - i]) { flag = false; break; }
        if (flag) cout << "Goldbach's conjecture is wrong.\n"; 
        else cout << n << " = " << i << " + " << n-i << '\n';
    }
    return 0;
}
