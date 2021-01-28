#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

struct compare {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
pii arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue <pii, vector<pii>, compare> pq;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + N);
	int cnt = 1;
	pq.push(arr[0]);
	for (int i = 1; i < N; i++)
	{
		pii tmp = pq.top();
		if (tmp.second <= arr[i].first)
		{
			pq.pop();
		}
		else
		{
			cnt++;
		}
		pq.push(arr[i]);

	}

	cout << cnt << endl;



	return 0;
}