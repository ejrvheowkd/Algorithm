#include <iostream>

using namespace std;

int main()
{
	int A, Z, K;
	long long list[201][201] = { 1 };
	cin >> A >> Z >> K;
	for (int i = 1; i <= A + Z; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				list[i][j] = 1;
			else
			{
				if (list[i - 1][j] + list[i - 1][j - 1] > 1000000000)
					list[i][j] = 1000000000;
				else
					list[i][j] = list[i - 1][j] + list[i - 1][j - 1];
			}
		}
	}
	int sum = A + Z;
	int a = A, z = Z;
	if (K > list[sum][z])
	{
		cout << -1 << endl;
	}
	else
	while (1)
	{
		if (list[sum - 1][z] < K)
		{
			K -= list[sum - 1][z];
			z--;
			cout << 'z';
		}
		else
		{
			cout << 'a';
		}
		sum--;
		if (K == 0)
			break;
		else if (z == 0)
		{
			while (sum--)
				cout << 'a';
			break;
		}

	}
	return 0;
}