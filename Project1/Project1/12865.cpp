#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int N, K;

pii arr[101];
int check[100001] = { 0 },sum=0,maxim=-1;
void caculate(int w,int i)
{
	
	
}
bool compare(const pii &a,const pii &b)
{
	return a.first > b.first;
}
int main()
{
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = K; j >= arr[i].first; j--)
		{
			if (check[j] < check[j -arr[i].first]+arr[i].second)
				check[j] = check[j - arr[i].first] + arr[i].second;
		}
	}
	cout << check[K] << endl;
	return 0;
}