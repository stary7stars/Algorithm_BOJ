// 1010번 : 다리 놓기
#include <iostream>
using namespace std;
long long C[31][31];
int main()
{
    int T, N, M, n, r;
    cin >> T;
    C[0][0] = 1ll;
    for (n = 1; n <= 30; n++)
    {
        C[n][0] = C[n][n] = 1ll;
        for (r = 1; r <= n; r++)
            C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]);
    }
    for (int t = 1; t <= T; t++) 
    { 
        cin >> N >> M; 
        cout << C[M][N] << '\n'; 
    }
    return 0;
}