#include <iostream>

using namespace std;

int main()
{
	string square[50];
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		//for (int j = 0; j < M; j++)
		{
			cin >> square[i];
		}
	}
	int max = 0;
	for (int i = 0; i <N ; i++)
	{
		for (int j = 0; j < M-1; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				if (square[i][j]-'0' == square[i][k] - '0' && k - j > max)
				{
					if ((i + (k - j)) < N)
					{
						if (square[i + (k - j)][j] - '0' == square[i][j] - '0' && square[i + (k - j)][k] - '0' == square[i][j] - '0')
						{
							max = k - j;
						}
					}
				}
			}
		}
	}
	max++;
	cout << max * max << endl;
	return 0;
}