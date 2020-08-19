// 2206번 : 벽 부수고 이동하기
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF (987654321)
typedef pair<int, int> P;
typedef pair<P, int> PI;
int map[1002][1002];
int visited[2][1002][1002]; // 0: 깰 찬스 없음, 1: 깰 찬스 있음
int dX[4] = { 0, 0, -1, 1 };
int dY[4] = { -1, 1, 0, 0 };

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int n = 1; n <= N; n++) {
		char * str;
		str = new char[M+1];
		scanf("%s", str + 1);
		for (int m = 1; m <= M; m++) {
			map[n][m] = str[m] - '0';
			visited[0][n][m] = visited[1][n][m] = INF;
		}
	}

	queue<PI> q;
	q.push(PI(P(1, 1), 1));
	visited[1][1][1] = 0;

	while (!q.empty()) {
		PI now = q.front(); q.pop();
		int X = now.first.second;
		int Y = now.first.first;
		int breakable = now.second;

		for (int d = 0; d < 4; d++) {
			int nX = X + dX[d];
			int nY = Y + dY[d];
			int cost = visited[breakable][Y][X] + 1;
			int nbreakable = breakable;
			if (nX < 1 || nX > M || nY < 1 || nY > N) continue;
			if (map[nY][nX] == 1) {
				if (breakable == 0) continue;
				nbreakable = 0;
			}
			
			if (visited[nbreakable][nY][nX] > cost) {
				q.push(PI(P(nY, nX), nbreakable));
				visited[nbreakable][nY][nX] = cost;
			}
		}
	}
	
	int ans = visited[0][N][M] <= visited[1][N][M] ? visited[0][N][M] : visited[1][N][M];
	printf("%d\n", ans == INF ? -1 : ans + 1);

	return 0;
}