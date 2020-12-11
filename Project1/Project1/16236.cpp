#include <iostream>
#include <queue>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
typedef struct {
	int x;
	int y;
	int d;
}INFO;
int main()
{
	/*
		N*N ũ�� M���� ����� �Ѹ��� �Ʊ���(ũ�� 2)
		�ƻ�1�ʿ� �����¿� ������ ���� But , �ڽź��� ũ�� �� �������� ������ �������� �ͱ����� ���� ������ �Դ°� ��������
		����� ������ ������ ���󿡰� ���� ��û
		�ڽ��� ũ��� ���� ���� ����⸦ ������ ũ�� 1 ����
		���� ���������� ���� ����� �ٵ� �Ÿ��� ������ ���� �� �ٵ� ���� ������ ���� ����
	*/
	int N, arr[20][20] = { 0 }, now_x = 0, now_y = 0, size = 2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				arr[i][j] = 0;
				now_x = i, now_y = j;
			}
		}
	}
	int time=0,cnt=0;
	while (1)
	{
		int check[20][20] = { 0 },mini = 100000000;;
		check[now_x][now_y] = 1;

		queue <INFO> q;
		int flag = 0;
		q.push({ now_x, now_y,0});
		int p_x=-1, p_y=-1;
		while (!q.empty())
		{
			INFO tmp = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int x = tmp.x + dx[j], y = tmp.y + dy[j], d = tmp.d;

				if (x < 0 || x >= N || y < 0 || y >= N)//�������ΰ� üũ
				{
					continue;
				}

				if (check[x][y] == 1)//��湮 üũ
					continue;
				else
					check[x][y] = 1;

				if (arr[x][y] == 0)//�������� �ִ�.
				{
					if (d + 1 < mini)//�������µ� �Ÿ��� �� �ִ�(�켱����1)
						q.push({ x, y,d + 1 });
				}
				else
				{
					if (arr[x][y] <= size)//�������� �ִ�
					{

						if (size > arr[x][y])
						{
							//����� �۴�.
							if (d + 1 == mini)//���� �����̴�.�켱 ����
							{
								if (p_x == x)
								{
									if (p_y > y)
										p_y = y;
								}
								else
								{
									if (p_x > x)
									{
										p_x = x;
										p_y = y;
									}
								}
							}
							else if (d + 1 < mini)
							{
								p_x = x;
								p_y = y;
								mini = d + 1;
							}
						}
						else if (size == arr[x][y])
						{
							//����� ����.
							if (d + 1 < mini)
							{
								q.push({ x, y,d + 1 });
							}
						}

					}
				}
			}
		}

		if (mini == 100000000)
		{
			break;
		}
		else
		{
			//������Ʈ
			time += mini;
			cnt++;
			now_x = p_x;
			now_y = p_y;
			arr[now_x][now_y] = 0;
			if (cnt == size)
			{
				size++;
				cnt = 0;
			}
		}
	}

	cout << time << endl;

	return 0;
}