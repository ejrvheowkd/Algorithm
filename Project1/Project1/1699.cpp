#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int list[100001];

int main()
{
	int N, n = 0, cnt = 0;
	int check[100001] = { 0 };
	cin >> N;
	for (int i = 1; i <= N; i++)
		check[i] = i;

	for (int i = 2; i * i <= N; i++)
	{
		for (int j = 4; j <= N; j++)
		{
			if (j - i * i == 0)
				check[j] = 1;
			else if (j - i * i > 0)
			{
				check[j] = min(check[j], check[j - i * i] + 1);
			}
		}
	}
	cout << check[N] << endl;
	return 0;
}