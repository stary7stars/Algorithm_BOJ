// 사전
#include <iostream>
using namespace std;

#define INF (1ll << 60)
int N, M, K, Tot;
long long nCr[205][205];
char Ans[204];

int main()
{
    cin >> N >> M >> K;
    
    nCr[0][0] = 1;
    for (int n = 1; n <= 200; n++)
    {
        nCr[n][0] = nCr[n][n] = 1ll;
        for (int k = 1; k < n; k++)
        {
            nCr[n][k] = nCr[n - 1][k - 1] + nCr[n - 1][k];
            if (nCr[n][k] > INF) nCr[n][k] = INF + 1;
        }
    }

    Tot = N + M;
    if (nCr[Tot][M] < K) cout << -1 << endl;
    else {
        for (int i = 0; i < Tot; i++)
        {
            if (nCr[Tot - 1 - i][M] >= K) Ans[i] = 'a';
            else 
            {
                Ans[i] = 'z';
                K -= nCr[Tot - 1 - i][M--];
                
            }
        }
        Ans[Tot] = '\0';
        cout << Ans << endl;
    }

    return 0;
}
