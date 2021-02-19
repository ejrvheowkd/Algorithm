#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, T, G, check[100000] = { 0 },cnt=0;
	queue <int> q;
	cin >> N >> T >> G;
	q.push(N);
	check[N] = 1;
	while (!q.empty())
	{
		if (check[G] != 0)
			break;
		int size = q.size();
		cnt++;
		if (cnt > T)
			break;
		while (size--)
		{
			int tmp = q.front();
			q.pop();
			for (int i = 0; i < 2; i++)
			{
				int x;
				if (i == 0)
				{
					x = tmp + 1;

					if (x > 99999)
						continue;
					if (check[x] == 0)
					{
						check[x] = 1;
						q.push(x);
					}
				}
				else
				{
					x = tmp * 2;
					int key = 10000;
					int num = x;
					if (x > 99999)
						continue;
					while (1)
					{
						if (x == 0)
						{
							break;
						}
						else if (x / key == 0)
							key /= 10;
						else
						{
							x = x - key;
							break;
						}
					}
					if (check[x] == 0)
					{
						check[x] = 1;
						q.push(x);
					}

				}
			}
			if (check[G] != 0)
				break;
		}
		if (check[G] != 0)
			break;
	}
	if (check[G] == 0)
		cout << "ANG" << endl;
	else
		cout << cnt << endl;
	return 0;
}