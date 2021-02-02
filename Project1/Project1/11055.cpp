#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int list[1001] = { 0 },dp[1001] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
		dp[i] = list[i];
		for (int j = 0; j < i; j++)
		{
			if (list[i] > list[j] && dp[j] + list[i] > dp[i])
				dp[i] = dp[j] + list[i];
		}
	}
	int maxim = 0;
	for (int i = 0; i < N; i++)
		maxim = max(maxim, dp[i]);

	cout << maxim << endl;
	return 0;
}