#include <iostream>

using namespace std;

typedef struct
{
	long long A;
	long long B;
	long long C;
	long long cut;
}INFO;
int N, K, D;
INFO info[1000001];
int l = 0, r = 1000001;
int main()
{
	
	cin >> N >> K >> D;
	for (int i = 0; i < K; i++)
	{
		cin >> info[i].A >> info[i].B >> info[i].C;
		info[i].cut = (info[i].B - info[i].A) / info[i].C + 1;
	}
	r = N;
	while (1 + l < r)
	{
		long long mid = (l + r) / 2;
		long long sum = 0;
		for (int i = 0; i < K; i++)
		{
			if (info[i].A > mid)
				continue;
			else if (info[i].B <= mid)
			{
				sum += info[i].cut;
			}
			else
			{
				sum++;
				long long tmp = mid - info[i].A;
				sum += tmp / info[i].C;
			}
		}

		if (sum < D)
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