#include <iostream>
#include <vector>
using namespace std;

char board[3][3];
int check[3][3] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int sum = 0;
int N, M;
vector <pair<int, int>> v;

void PM(int x, int y, char c);//+,- ���
void BPM(int x, int y, char c);//+,- �ٽ� ������ 
int caculate(int x, int y, char c, int cnt);

int main()
{
	/*
		3*3 ���ڿ� ���� , (+/-) ������ �ִ�.
		�������ϴ� ���� N , ����ؾ� �ϴ� ���� ���� M
		�������� �ٽ� ���ư� ������.
	*/
	cin >> N >> M;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 3;i++)
	{
		for (int j = i%2;j<3;j+=2)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int kk = 0; k < 3; k++)
					check[k][kk] = 0;
			}
			if (caculate(i, j, 0, 0) == 1)
			{
				cout << i << " " << j << endl;
				while (!v.empty())
				{
					cout << v.back().first << " " <<v.back().second  << endl;
					v.pop_back();
				}
				return 0;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}

int caculate(int x, int y, char c, int cnt)
{
	char tmp = c;
	int tcnt = cnt;
	if (check[x][y] == 1)
		return 0;;
	check[x][y] = 1;
	if (tmp == '0')
		tmp = board[x][y];
	else
	{
		PM(x, y, c);
		tcnt++;
		tmp = '0';
	}
	if (sum == N && tcnt == M)
	{
		cout << "1" << endl;
		return 1;
	}
	else if (tcnt == M)
	{
		if (tmp == '0')
		{
			BPM(x, y, c);
		}
		check[x][y] = 0;
		return 0;
	}
	for (int i = 0; i < 4; i++)
	{
		int f = dx[i] + x;
		int e = dy[i] + y;
		if (f < 0 || e < 0 || f >= 3 || e >= 3)
			continue;
		if (caculate(f, e, tmp, tcnt) == 1)
		{
			v.push_back(make_pair(f, e));
			return 1;
		}
	}
	if (tmp == '0')
	{
		BPM(x, y, c);
	}
	check[x][y] = 0;
	return 0;
}
void PM(int x, int y, char c)//+,- ���
{
	if (c == '-')
	{
		sum -= board[x][y] - '0';
	}
	else
	{
		sum += board[x][y] - '0';
	}
}
void BPM(int x, int y, char c)//+,- �ٽ� ������ 
{
	if (c == '-')
	{
		sum += board[x][y] - '0';
	}
	else
	{
		sum -= board[x][y] - '0';
	}
}