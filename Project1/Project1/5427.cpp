#include <iostream>
#include <queue>
#define pii pair<int,int>
using namespace std;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int w, h, firetime[1001][1001] = { 0 }, cnt = 1, check[1001][1001] = { 0 };
		char board[1001][1001];
		pii S, F;
		queue <pii> fire,escape;
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '@')
				{
					S = pii{ i,j };
					escape.push(pii{ i,j });
					check[i][j] = 1;
					
				}
				if (board[i][j] == '*')
				{
					F = pii{ i,j };
					fire.push(pii{ i,j });
					firetime[i][j] = 1;
				}
			}
		}
		while (!fire.empty())
		{
			int size = fire.size();
			cnt++;
			while (size--)
			{
				pii tmp = fire.front();
				fire.pop();
				for (int i = 0; i < 4; i++)
				{
					int x = tmp.first + dx[i];
					int y = tmp.second + dy[i];
					if (x < 0 || y < 0 || x >= h || y >= w)
						continue;
					if (firetime[x][y] == 0 && (board[x][y] == '.'|| board[x][y] == '@'))
					{
						firetime[x][y] = cnt;
						fire.push(pii{ x,y });
					}
				}
			}
		}
		cnt = 0;
		int flag = 0;
		while (!escape.empty())
		{
			cnt++;
			int size = escape.size();
			while (size--)
			{
				pii tmp = escape.front();
				escape.pop();
				for (int i = 0; i < 4; i++)
				{
					int x = tmp.first + dx[i];
					int y = tmp.second + dy[i];
					if (x < 0 || y < 0 || x >= h || y >= w)
					{
						cout << cnt << endl;
						flag = 1;
						break;
					}
					if (check[x][y] == 0 && board[x][y] == '.' && ((firetime[x][y] - 1 > cnt)||firetime[x][y]==0))
					{
						escape.push(pii{ x,y });
						check[x][y] = 1;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << "IMPOSSIBLE" << endl;
		
	}
	return 0;
}