#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, S, E, M, check[101] = { 0 }, cnt = 0;
	vector <int> v[101];
	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue <int> q;
	q.push(S);
	check[S] = 1;
	while (!q.empty())
	{
		int size = q.size();
		cnt++;
		while (size--)
		{
			int key = q.front();
			q.pop();
			for (int i = 0; i < v[key].size(); i++)
			{
				int t = v[key][i];
				if (check[t] == 0)
				{
					check[t] = 1;
					q.push(t);
				}
			}
			if (check[E] != 0)
				break;
		}
		if (check[E] != 0)
			break;
	}
	if (check[E] == 0)
		cout << -1 << endl;
	else
	cout << cnt << endl;
	return 0;
}