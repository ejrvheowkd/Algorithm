#include <iostream>
#include <queue>

using namespace std;

typedef struct {
	int n;
	string s;
}INFO;
int caculate(int key,int num)
{
	if (key == 0)
	{
		num *= 2;
		if (num > 9999)
			num %= 10000;
		return num;
	}
	else if (key == 1)
	{
		num -= 1;
		if (num < 0)
			num = 9999;
		return num;
	}
	else if (key == 2)
	{
		num = (num - 1000 * (num / 1000)) * 10 + (num / 1000);
		return num;
	}
	else
	{
		num = (num / 10) + 1000 * (num % 10);
		return num;
	}
}
int main()
{
	int T;
	cin >> T;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (T--)
	{
		int a, b, check[10001] = { 0 };
		cin >> a >> b;
		queue <INFO> q;
		q.push(INFO{ a,"" });
		check[a] = 1;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				INFO tmp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int result =caculate(i,tmp.n);
					if (check[result] == 0)
					{
						check[result] = 1;
						string ss= tmp.s;
						ss.push_back(i);
						q.push(INFO{ result,ss });
						if (result == b)
						{
							for (int i = 0; i < ss.size(); i++)
							{
								if (ss[i] == 0)
									cout << 'D';
								else if (ss[i] == 1)
									cout << 'S';
								else if (ss[i] == 2)
									cout << 'L';
								else
									cout << 'R';
							}
							cout << "\n";
							break;
						}
					}
				}
				if (check[b] != 0)
					break;
			}
			if (check[b] != 0)
				break;
		}
		
	}
	return 0;
}