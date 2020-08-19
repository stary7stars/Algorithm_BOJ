// 1726번 : 로봇
#include <stdio.h>
#define MAX (110)
#define OUT_Q(X) ((X) = Que[Rp++])
typedef struct _RO { int X, Y, D; }RO;

RO Que[MAX * MAX * 4];
int Map[MAX][MAX];
int Visit[5][MAX][MAX];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int chdir[5][3] = {
	{0, 0, 0},
	{0, 3, 4},
	{0, 4, 3},
	{0, 2, 1},
	{0, 1, 2},
};

int M, N; // 세로가 M 임
int Wp, Rp;
int Gx, Gy, Gd;

void Input(void);
int BFS(void);

int main(void)
{
	Input();
	printf("%d\n", BFS());
	return 0;
}

void Input(void)
{
	int i, j;
	int sx, sy, sd;
	Wp = Rp = 0;

	scanf("%d %d", &M, &N);
	for (i = 1; i <= M; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &Map[i][j]);
		}
	}

	scanf("%d %d %d", &sy, &sx, &sd);
	Que[Wp++] = (RO) { sx, sy, sd };
	Visit[sd][sy][sx] = 1;

	scanf("%d %d %d", &Gy, &Gx, &Gd);

	for (i = 0; i <= M + 1; i++)
	{
		Map[i][0] = Map[i][N + 1] = 1;
	}
	for (i = 0; i <= N + 1; i++)
	{
		Map[0][i] = Map[M + 1][i] = 1;
	}
}

int BFS(void)
{
	int i, j;
	int ox, oy, ov;
	int nx, ny;
	int tmp;
	int res = 987654321;
	RO now = (RO) { 0 };

	while (Wp > Rp)
	{
		OUT_Q(now);
		ox = nx = now.X;
		oy = ny = now.Y;
		ov = Visit[now.D][now.Y][now.X];
		for (i = 1; i <= 2; i++)
		{
			int dir = chdir[now.D][i];
			if (Visit[dir][ny][nx]) continue;
			Que[Wp++] = (RO) { nx, ny, dir };
			Visit[dir][ny][nx] = ov + 1;
        }
		for (j = 1; j <= 3; j++)
		{
			nx += dx[now.D];
			ny += dy[now.D];
			if (Map[ny][nx]) break;
			if (Visit[now.D][ny][nx]) continue;
			Que[Wp++] = (RO) { nx, ny, now.D };
			Visit[now.D][ny][nx] = ov + 1;
		}
	}

	return Visit[Gd][Gy][Gx] - 1;
}