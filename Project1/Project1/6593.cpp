#include <iostream>
#include <queue>

using namespace std;
int dx[6] = { 0,0,1,-1,0,0 }, dy[6] = { 0,0,0,0,1,-1 }, dz[6] = { -1,1,0,0,0,0 };
typedef struct
{
	int z;
	int x;
	int y;
}INFO;

int main()
{
	while (1)
	{
		int L, R, C, check[31][31][31] = { 0 },cnt=0;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		char arr[31][31][31];
		queue <INFO> q;
		INFO key;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
					{
						q.push(INFO{ i, j, k });
						check[i][j][k] = 1;
					}
					if (arr[i][j][k] == 'E')
						key = INFO{ i,j,k };
				}
			}
		}
		while (!q.empty())
		{
			if (check[key.z][key.x][key.y] != 0)
				break;
			cnt++;
			int size = q.size();
			while (size--)
			{
				INFO tmp = q.front();
				q.pop();
				for (int i = 0; i < 6; i++)
				{
					int x = dx[i] + tmp.x;
					int y = dy[i] + tmp.y;
					int z = dz[i] + tmp.z;
					if (x < 0 || y < 0 || z < 0 || x >= R || y >= C || z >= L)
					{
						continue;
					}
					if (check[z][x][y] == 0&&(arr[z][x][y]=='.'||arr[z][x][y]=='E'))
					{
						check[z][x][y] = 1;
						q.push(INFO{ z,x,y });
					}
				}
				if (check[key.z][key.x][key.y] != 0)
					break;
			}
			if (check[key.z][key.x][key.y] != 0)
				break;
		}
		if (check[key.z][key.x][key.y] == 0)
			cout << "Trapped!" << endl;
		else
		cout <<"Escaped in "<<cnt<<" minute(s)."<< endl;
	}
	return 0;
}