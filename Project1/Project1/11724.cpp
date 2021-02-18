#include <iostream>
#include <vector>
using namespace std;

vector <int> v[1001];
int check[1001];
void dfs(int num)
{
	check[num] = 1;
	int size = v[num].size();
	for (int i = 0; i < size; i++)
	{
		int tmp = v[num].back();
		v[num].pop_back();
		if (check[tmp] == 0)
		{
			dfs(tmp);
		}
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n,m;
		cin >> n >> m;
		v[n].push_back(m);
		v[m].push_back(n);
	}
	int cnt = 0;
	for (int i = 1; i <=N; i++)
	{
		if (check[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}


	cout << cnt << endl;


	return 0;
}