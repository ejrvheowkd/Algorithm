#include <iostream>

using namespace std;

int main()
{
	long long N, M,l=0,r=0;
	long long list[10000] = { 0 };
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
		if (r < list[i])
			r = list[i];
	}
	r += 1;
	while (1 + l < r)
	{
		long long cnt = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < N; i++)
		{
			cnt += list[i] / mid;
		}

		if (M <= cnt)
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