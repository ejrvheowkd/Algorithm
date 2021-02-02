#include <iostream>

using namespace std;

pair <int, int> list[1000000];

int main()
{
	int l, w, h,N;
	int result[21] = { 0 };
	cin >> l >> w >> h>>N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		list[i].first = a;
		list[i].second = b;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		int tmp = 1<<list[i].first;
		long long res = 1;
		res *= l / tmp;
		res *= w / tmp;
		res *= h / tmp;
		long long sex = 0;
		for (int j = 0; j <=20; j++)
		{
			if (result[j] != 0)
			{
				long long tm = (1<<j) / tmp;
				sex += tm * tm * tm * result[j];
			}
		}
		res = res - sex;
		if (res > list[i].second)
			result[i] = list[i].second;
		else
			result[i] = res;
	}
	long long ssex = 0;
	long long fuck = 0;
	for (int i = 0; i < N; i++)
	{
		int ttt = 1 << i;
		fuck += result[i] * (ttt * ttt * ttt);
		ssex += result[i];
	}
	if (fuck != l * w * h)
		cout << -1 << endl;
	else
	cout << ssex << endl;
	return 0;
}