#include <iostream>
#include <algorithm>
#include <vector>
#define   pii pair<int, int>
using namespace std;

bool compare(const pii& a, const pii& b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main()
{
	int N, cost, list[10] = { 0 };
	vector <int>result;
	vector<pii> v;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
		v.push_back(pii{ list[i],i });
	}
	cin >> cost;

	if (N == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(v.begin(), v.end(),compare);

	if (v[0].second == 0)
	{
		if (cost - v[1].first < 0)
		{
			cout << 0 << endl;
			return 0;
		}
		result.push_back(v[1].second);
		cost -= v[1].first;
	}
	while (1)
	{
		if (cost - v[0].first < 0)
			break;
		result.push_back(v[0].second);
		cost -= v[0].first;
	}



	int now = N - 1;
	for (int i = 0; i < result.size(); i++)
	{
		int tmp = list[result[i]];
		while (now != 0)
		{
			if (cost - (list[now] - tmp) >= 0)
			{
				cost -= list[now] - tmp;
				result[i] = now;
				break;
			}
			else
			{
				now--;
			}
		}
		if (cost == 0||now==0)
			break;
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i];

	return 0;
}