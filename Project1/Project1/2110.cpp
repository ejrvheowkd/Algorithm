#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int N, M;
	long long l = 1, r = 0, list[200001] = { 0 };
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	sort(list, list + N);
	r = list[N - 1] + 1;
	while (l + 1 < r)
	{
		int cnt = 1;

		int left = list[0];
		long long mid = (l + r) / 2,sum=0;
		for (int i = 1; i < N; i++)
		{
			if (sum + list[i] - left < mid)
			{
				sum += list[i] - left;
				left = list[i];
			}
			else
			{
				cnt++;
				sum = 0;
				left = list[i];
			}
		}
		if (cnt >= M)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout << l << endl;
	return 0;
}