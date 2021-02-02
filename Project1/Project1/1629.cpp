#include <iostream>

using namespace std;

long long A, B, C;

long long caculate(int N)
{
	if (N == 1)
		return A%C;
	int l = N / 2;
	int r = N - l;
	long long result=caculate(l);
	result = result % C;
	if (l == r)
	{
		return (result * result)%C;
	}
	else
	{
		return (((result * result)%C) * A) % C;
	}
}
int main()
{
	cin >> A >> B >> C;
	long long result = 0;
	result = caculate(B);

	cout << result << endl;
	return 0;
}