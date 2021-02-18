#include <iostream>

using namespace std;
int check[100001], board[100001];

int dfs(int num)
{
	if (check[num] == 0)
	{
		check[num] = -1;
		int tmp=dfs(board[num]);
		if (tmp != -2)
		{
			check[num] = num;
			if (tmp == num)
				return -2;
			else
				return tmp;
		}
		else
		{
			check[num] = -2;
			return -2;
		}

	}
	else if (check[num] == -1)
	{
		return num;
	}
	else
	{
		return -2;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 1; i <=N; i++)
		{
			cin >> board[i];
			check[i] = 0;
		}
		for (int i = 1; i <=N; i++) {
			if (check[i]==0)
			{
				check[i] = -1;
				int tmp=dfs(board[i]);
				if (tmp == -2)
					check[i] = -2;
				else
				{
					check[i] = i ;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == -2)
				cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}