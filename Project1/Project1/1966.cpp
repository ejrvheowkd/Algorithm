#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

struct compar {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};
bool com(const int& a, const int& b)
{
	return a > b;
}
int main()
{
	int T, arr[100];
	cin >> T;
	while (T--)
	{
		priority_queue <pii,vector<pii>,compar> pq;
		queue <pii> q;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			pq.push(make_pair(i, tmp));
			q.push(make_pair(i,tmp));
			arr[i] = tmp;
		}
		int cnt = 0;
		sort(arr, arr + N,com);
		while (true)
		{
			pii tmp = pq.top();
			pq.pop();
			pii now;
			while (true)
			{
				now = q.front();
				q.pop();
				if (now.second == tmp.second)
				{
					cnt++;
					break;
				}
				else
					q.push(now);
			}
			if (now.first == M)
				break;

		}
		cout << cnt << endl;
		
	}
	return 0;
}