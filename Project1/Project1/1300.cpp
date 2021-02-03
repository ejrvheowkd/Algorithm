#include <iostream>

using namespace std;

int main()
{
	int N, M;
	unsigned long long l = 0, r;
	cin >> N >> M;
	r =N*N+1;
	while (l + 1 < r)
	{
		unsigned long long sum = 0;
		unsigned long long mid = (l + r) / 2;
		for (int i = 1; i <= N; i++)
		{
			unsigned long long tmp = mid / i;
			if (tmp > N)
			{
				sum += N;
			}
			else
			{
				sum += tmp;
			}
		}
		if (sum < M)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	cout << r << endl;
	return 0;
}