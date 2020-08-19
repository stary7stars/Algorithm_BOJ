#include <stdio.h>
#define MAX (20)
int Time[MAX];
int Profit[MAX];
int Pre_Sum[MAX];

int N, M;
int Max;

void Input(void);
void DFS(int d, int s);

int main(void)
{
    Input();
    DFS(1, 0);
    printf("%d\n", Max);
    return 0;
}

void Input(void)
{
    int i;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &Time[i], &Profit[i]);
    }

    for (i = N; i >= 1; i--)
    {
        if (i + Time[i] <= N + 1) break;
    }
    M = i;

    for (i = M; i>= 1; i--)
    {
        Pre_Sum[i] = Pre_Sum[i + 1] + Profit[i];
    }

    Max = 0;
}

void DFS(int d, int s)
{
    if (s + Pre_Sum[d] <= Max) return;
    if (d > M)
    {
        if (Max < s) Max = s;
        return;
    }

   //printf("[%d] %d %d\n", d, Time[d], s + Profit[d]);
    if (d + Time[d] <= N + 1) DFS(d + Time[d], s + Profit[d]);
    DFS(d + 1, s);
}