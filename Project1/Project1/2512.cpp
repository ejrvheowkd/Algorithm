#include <iostream>

using namespace std;

int main()
{
	long long N,M, list[10001] = { 0 };
	int l = 0, r = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
		if (r < list[i])
			r = list[i];
	}

	cin >> M;
	r=r + 1;
	while (l + 1 < r)
	{
		long long mid = (l + r) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (mid < list[i])
			{
				sum += mid;
			}
			else
			{
				sum += list[i];
			}
		}
		if (sum <= M)//가능하다
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