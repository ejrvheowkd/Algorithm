#include <iostream>

using namespace std;
int N, S, arr[21] = { 0 };
int sum=0,check[21],cnt;

int caculate(int c)
{
	
	if (c == N)
	{
		if (sum == S)
			cnt++;
		return 0;
	}

	sum += arr[c];
	caculate(c + 1);
	sum -= arr[c];
	caculate(c + 1);
	
	return 0;
}
int main()
{
	cin >> N >> S;
	for (int i =0; i < N; i++)
		cin >> arr[i];

		caculate(0);
		if (S == 0)
			cnt--;
	cout << cnt << endl;
	return 0;
}