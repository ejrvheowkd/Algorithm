/*#include <iostream>

using namespace std;

int arr[1000][4][1000] = { 0 };
int deep(int d,int num,int cnt);
int N, K;

int main()
{
	cin >> N >> K;
	if (K == 1)
	{
		cout << N << endl;
	}
	else if (K > N / 2)
	{
		cout << 0 << endl;
	}
	else
	{
		cout<<deep(N, 0,0)<<endl;
	}
	return 0;
}

int deep(int d,int num,int cnt) {
	if (N % 2 == 0)
	{
		arr[0][0][0] = 1;
		arr[0][1][1] = 1;
		arr[0][2][1] = 1;
		num += 2;
	}
	else
	{
		arr[0][0][0] = 1;
		arr[0][0][1] = 1;
		arr[0][1][1] = 1;
		arr[0][2][1] = 1;
		arr[0][3][2] = 1;
		num += 3;
	}
	
	while (true)
	{
		if (num >= N||N==1||N==2||N==3)
		{
			break;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= N / 2; j++) {
				if (arr[cnt][i][j] != 0)
				{
					if (i == 0)
					{
						arr[cnt + 1][0][j] += arr[cnt][0][j];
						arr[cnt + 1][0][j] %= 1000000003;
						
						arr[cnt + 1][1][j + 1] += arr[cnt][0][j];
						arr[cnt + 1][1][j+1] %= 1000000003;

						arr[cnt + 1][2][j + 1] += arr[cnt][0][j];
						arr[cnt + 1][2][j+1] %= 1000000003;

						arr[cnt + 1][3][j + 2] += arr[cnt][0][j];
						arr[cnt + 1][3][j+2] %= 1000000003;
					}
					if(i==1)
					{
						arr[cnt + 1][0][j] += arr[cnt][1][j];
						arr[cnt + 1][0][j] %= 1000000003;
						
						arr[cnt + 1][2][j + 1] += arr[cnt][1][j];
						arr[cnt + 1][2][j+1] %= 1000000003;
					
					}
					if (i == 2) {
						arr[cnt + 1][0][j] += arr[cnt][2][j];
						arr[cnt + 1][0][j] %= 1000000003;
						
						arr[cnt + 1][1][j + 1] += arr[cnt][2][j];
						arr[cnt + 1][1][j+1] %= 1000000003;
					}
					if (i == 3)
					{ 
						arr[cnt + 1][0][j] += arr[cnt][3][j];
						arr[cnt + 1][0][j] %= 1000000003;
					}
				}
			}
		}
		cnt++;
		num += 2;
	}
	return ((arr[cnt][0][K] + arr[cnt][1][K]) % 1000000003 + (arr[cnt][2][K])%1000000003) % 1000000003;
}*/

#include <iostream>

using namespace std;
int dp[1001][1001] = { 0 };

int main() {

	int N, K;
	cin >> N >> K;
	if (K == 1)
		cout << N << endl;
	else if (N / 2 < K)
		cout << 0 << endl;
	else
	{
		for (int i = 1; i < N; i++)
		{
			dp[i][0] = 1;
			dp[i][1] = i;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= N; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
			}
		}
		cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % 1000000003 << endl;

	}
	return 0;
}