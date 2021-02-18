#include <iostream>
#include <stack>
#include <algorithm>
#define pll pair<unsigned long long , unsigned long long >
using namespace std;

int main()
{
	stack <pll> st;
	unsigned long long arr[100001] = { 0 },maxim=0;
	unsigned long long N,cnt;
	cin >> N;
	for (int i = 0; i< N; i++)
	{
		cin >> arr[i];

	}
	st.push(make_pair(arr[0], 0));

	for (int i = 1; i < N; i++)
	{
		pll tmp = st.top();
		cnt = 1;
		if (tmp.first >= arr[i])
		{
			while (true)
			{
				maxim = max(maxim, tmp.first * (tmp.second + cnt));
				st.pop();
				if (st.empty() || st.top().first < arr[i])
				{
					st.push(make_pair(arr[i], tmp.second+cnt));
					break;
				}
				cnt += 1 + tmp.second;

				tmp = st.top();
			}
		}
		else
		{
			st.push(make_pair(arr[i], 0));
		}
	}
	cnt = 1;
	while (!st.empty())
	{
		maxim = max(maxim, st.top().first * (st.top().second + cnt));
		cnt+=1+ st.top().second;
		st.pop();
	}
	cout << maxim << endl;
	return 0;
}