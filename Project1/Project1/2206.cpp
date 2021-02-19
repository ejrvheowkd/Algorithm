#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };

typedef struct {
	int x;
	int y;
	int wall;
}INFO;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, check[1001][1001] = { 0 }, cnt = 1, wallcheck[1001][1001] = { 0 };
	string board[1001];
	queue <INFO> q;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	q.push(INFO{ 0,0,0 });
	check[0][0]=1;
	while (!q.empty())
	{
		if (N == 1 && M == 1)
			break;
		cnt++;
		int size = q.size();
		while(size--)
		{
			INFO tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = dx[i] + tmp.x;
				int y = dy[i] + tmp.y;
				if (x < 0 || y < 0 || x >= N || y >= M)
					continue;
				if (check[x][y] == 0 && board[x][y] == '0')
				{
					if (tmp.wall == 1)
					{
						wallcheck[x][y] = 1;
					}
					check[x][y] = 1;
					q.push(INFO{ x,y,tmp.wall });
				}
				else if (check[x][y] == 1 && wallcheck[x][y] == 1&&tmp.wall==0)
				{
					wallcheck[x][y] = 0;
					q.push(INFO{ x,y,0 });
				}
				else if (check[x][y] == 0 && board[x][y] == '1'&&tmp.wall==0)
				{
					check[x][y] = 1;
					q.push(INFO{ x,y,1 });
				}
			}
			if (check[N - 1][M - 1] != 0)
				break;
		}

		if (check[N - 1][M - 1] != 0)
			break;
	}

	if (check[N - 1][M - 1] == 0)
		cout << -1 << endl;
	else
		cout << cnt << endl;

	return 0;
}