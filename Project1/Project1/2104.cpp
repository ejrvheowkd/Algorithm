#include <iostream>
#include <algorithm>
using namespace std;
int maxim = -1e9;
long long list[100001], psum[100001];

long long  caculate(int l, int r)
{
	if (l == r)
	{
		return list[l] * list[l];
	}
	long long ret= max(caculate(l, (l + r) / 2), caculate((l + r) / 2 + 1, r));

	int ll = (l + r) / 2;
	int rr = ll;
	long long mini = list[ll];
	while (ll!=l||rr!=r) 
	{
		if (ll == l || (rr<r&&(list[rr + 1] > list[ll - 1])))
		{
			rr++;
			if (mini > list[rr])
				mini = list[rr];
		}
		else
		{
			ll--;
			if (mini > list[ll])
				mini = list[ll];
		}
		ret = max(ret,( psum[rr] - psum[ll - 1])*mini);
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <=N; i++)
	{
		cin >> list[i];
		psum[i] = psum[i - 1] + list[i];
	}
	cout << caculate(1, N) << endl;;

	return 0;
}