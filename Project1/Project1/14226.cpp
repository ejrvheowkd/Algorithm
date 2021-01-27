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
			//ù��°
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
2���� �迭�� ����ϴٰ� ������ ���� ������ �ƴϴ��� ���忡 ����� S������ ���� ������
�ڿ����� �� ���� ���� �ִٴ� ���� �������� ���ߴ�.

BFS�� �ϸ� ������ �ð��� ���� ���� �����ϴ� ���̰� ���� �����Ƿ� BFS�� Ǯ����.
*/