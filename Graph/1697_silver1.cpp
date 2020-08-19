// 1697번 : 숨바꼭질
#include <stdio.h>

#define MAX (100100)

int Que[MAX * 4];
int Arr[MAX];
int dx[] = { 0, 1, -1 };

int Wp, Rp;
int S;
int D;

void Input(void);
void In_Q(int x);
int Out_Q(void);
int BFS(int x);

int main(void)
{
	Input();
	printf("%d\n", BFS(S));

	return 0;
}

void Input(void)
{
	scanf("%d %d", &S, &D);
	Arr[D] = 0;
}

void In_Q(int x)
{
	Que[Wp++] = x;
}

int Out_Q(void)
{
	return Que[Rp++];
}

int BFS(int x)
{
	int out;
	int i;
	int nx;

	In_Q(x);
	Arr[x] = 0;
	dx[0] = x;

	//for (i = 0; i <= 20; i++)
	//{
	//	printf("%2d ", i);
	//}
	//printf("\n");

	if (x == D) return Arr[x];

	while (Wp > Rp)
	{
		out = Out_Q();
		dx[0] = out;

		if (out > D)
		{
			nx = out + dx[2];

			if (nx >= MAX || nx < 1) continue;
			if (nx == D) return Arr[out] + 1;

			if (!Arr[nx])
			{
				In_Q(nx);
				Arr[nx] = Arr[out] + 1;
			}
		}
		else
		{
			for (i = 0; i < 3; i++)
			{
				nx = out + dx[i];

				if (nx >= MAX || nx < 1) continue;
				if (nx == D) return Arr[out] + 1;
				if (!Arr[nx])
				{
					In_Q(nx);
					Arr[nx] = Arr[out] + 1;
				}
			}
		}
		/*for (i = 0; i <= 20; i++)
		{
			printf("%2d ", Arr[i]);
		}
		printf("\n");*/
	}
}