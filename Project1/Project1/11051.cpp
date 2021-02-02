#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	if (K > N / 2 + 1)
		K = N - K;
	int result[1001][1002] = { {0},{0,1,1},{0,1,2,1} };
	for (int i = 3; i <= N; i++)
	{
		for (int j = 1; j <= (i)/2+1; j++)
		{
			if (j == 1)
				result[i][j] = 1;
			else
			{
				result[i][j] = (result[i - 1][j - 1] + result[i - 1][j])%10007;
			}
		}
		if (i % 2 != 0)
		{
			result[i][i / 2 + 2] = result[i][i / 2 + 1];
		}
	}
	cout << result[N][K+1];

	return 0;
}