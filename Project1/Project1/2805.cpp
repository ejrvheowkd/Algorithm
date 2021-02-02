#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	long long list[1000001] = { 0 };
	cin >> N >> M;
	long long l = 0, r = 0, sex;
	for (int i = 1; i <=N; i++)
	{
		cin >> list[i];
		if (list[i] > r)
			r = list[i];
	}
	while (l+1<r)
	{
		long long mid = (l + r) / 2;
		long long sum = 0;
		for (int i = 1; i <= N; i++)
		{
			long long  result = list[i] - mid;
			if (result >= 0)
				sum += result;
		}
		if (sum >= M)
		{
			l = mid;
		}
		else if (sum < M)
		{
			r = mid;
		}
	}
	cout << l << endl;

	return 0;
}