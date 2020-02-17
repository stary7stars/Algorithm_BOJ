//집합의 표현
#include <cstdio>

int parent[1000100];

int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

int main()
{
	int n, m;
	int q, a, b;

	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &q, &a, &b);
		if (q == 1) 
		{ 
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
		else parent[find(b)] = find(a);
	}

	return 0;
}
