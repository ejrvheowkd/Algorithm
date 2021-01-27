#include <iostream>
#include <queue>
using namespace std;
bool visited[2000][2000] = { 0 };

int main()
{
	int s,n;
	cin >> s;
	queue <pair<int, int>> q;
	q.push(make_pair(1, 0));
	visited[1][0] = true;
	int time=0;
	while (!q.empty())
	{
		int size = q.size();
		while (size--) {
			int len = q.front().first;
			int clip = q.front().second;
			q.pop();

			if (len == s)
			{
				cout << time << endl;
				return 0;
			}
			//첫번째
			int c = len;
			if (!visited[len][c]) {
				q.push(make_pair(len, c));
				visited[len][c] = 1;
			}

			c = len + clip;
			if (!visited[c][clip] && c <= 1000)
			{
				q.push(make_pair(c, clip));
				visited[c][clip] = 1;
			}
			c = len - 1;
			if (!visited[c][clip] && c > 0) {
				q.push(make_pair(c, clip));
				visited[c][clip ] = 1;
			}
		}
		time++;
	}
	return 0;
}


/*
2차원 배열로 계산하다가 현재의 값이 최적이 아니더라도 보드에 저장된 S개수의 수가 많으면
뒤에서는 더 빠를 수가 있다는 점을 생각하지 못했다.

BFS로 하면 최적의 시간에 가장 빨리 도착하는 길이가 먼저 나오므로 BFS로 풀었다.
*/