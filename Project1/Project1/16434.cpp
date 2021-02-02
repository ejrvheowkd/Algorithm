#include <iostream>

using namespace std;

typedef struct {
	int flag;
	long long one;
	long long two;
}INFO;
int main()
{
	int N;
	long long l = 0, r = 1e18, atk;
	INFO info[123460];
	cin >> N >> atk;

	for (int i = 0; i < N; i++)
	{
		cin >> info[i].flag >> info[i].one >> info[i].two;
	}

	while (1 + l < r)
	{
		long long mid = (l + r) / 2,now=mid,flag=0;
		long long now_atk = atk;

		for (int i = 0; i < N; i++)
		{
			if (info[i].flag == 1)
			{
				long long tmp = info[i].two;
				long long win = tmp / now_atk,lose= now / info[i].one;
				if (tmp % now_atk != 0)
					win++;
				if (now % info[i].one != 0)
					lose++;
				if (win <= lose)
				{
					now -= (win-1) * info[i].one;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				now_atk += info[i].one;
				now += info[i].two;
				if (now > mid)
					now = mid;
			}
			if (flag)
				break;
		}
		if (flag)
		{
			l = mid;
		}
		else
			r = mid;
	}
	cout << r << endl;
	return 0;
}