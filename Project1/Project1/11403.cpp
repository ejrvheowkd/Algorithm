#include <iostream>
#include <vector>
using namespace std;
vector <int> v[101];
int N, board[101][101],check[101][101];
void dfs(int a,int b)
{
	check[a][b] = 1;
	for (int i = 0; i < v[b].size(); i++)
	{
		if (check[a][v[b][i]] == 0)
			dfs(a, v[b][i]);
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				v[i].push_back(j);
		}
	}
		for (int i = 0; i < N;i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (check[i][v[i][j]] == 0)
					dfs(i, v[i][j]);
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << check[i][j]<<" ";
			cout << endl;
		}
			return 0;
}