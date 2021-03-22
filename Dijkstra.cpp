#include <iostream>
using namespace std;
int main()
{
	int e[10][10], dis[10], book[10], i, j, n, m, start, end, weight, u, v, min;
	int inf = 99999999;
	cin >> n >> m;
	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= m;j++)
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}
	for (i = 1;i <= m;i++)
	{
		cin >> start >> end >> weight;
		e[start][end] = weight;
	}
	for (i = 1;i <= n;i++)
		dis[i] = e[1][i];
	for (i = 1;i <= n;i++)
		book[i] = 0;
	for (i = 1;i <= n - 1;i++)
	{
		min = inf;
		for (j = 1;j <= n;j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1;v <= n;v++)
		{
			if (e[u][v] < inf)
			{
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
	cout << dis[n];
	system("pause");

}