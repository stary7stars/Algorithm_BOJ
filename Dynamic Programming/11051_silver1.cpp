#include <iostream>
using namespace std;
int C[1001][1001];
int main()
{
    int N, R, n, r;
    cin >> N >> R;
    C[0][0] = 1;
    for (n = 1; n <= N; n++)
    {
        C[n][0] = C[n][n] = 1;
        for (r = 1; r <= n; r++)
            C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % 10007;
    }
    cout << C[N][R];
    return 0;
}