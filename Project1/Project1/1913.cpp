#include <iostream>
#include <algorithm>
using namespace std;

/*
ȸ�ǽ� ����
�־��� ������ ������ �̸� �������� �������� �� �� �ֵ��� �������
*/
pair<long, long> arr[100001];

bool cmp(const pair<int,int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N,cmp);
	
	int now = -1,cnt=1;
	for (int i = 0; i < N; i++)
	{
		if (now == -1)
			now = arr[i].second;
		else if (now <= arr[i].first)
		{
			now = arr[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}