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
		N*N 크기 M마리 물고기 한마리 아기상어(크기 2)
		아상1초에 상하좌우 움직임 가능 But , 자신보다 크면 못 지나가고 같으면 지나가는 것까지는 가능 작으면 먹는거 까지가능
		물고기 먹을게 없으면 엄상에게 도움 요청
		자신의 크기와 같은 수의 물고기를 먹으면 크기 1 증가
		만약 여러마리면 가장 가까운 근데 거리가 같으면 가장 위 근데 위도 같으면 가장 왼쪽
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

				if (x < 0 || x >= N || y < 0 || y >= N)//범위안인가 체크
				{
					continue;
				}

				if (check[x][y] == 1)//재방문 체크
					continue;
				else
					check[x][y] = 1;

				if (arr[x][y] == 0)//지나갈수 있다.
				{
					if (d + 1 < mini)//지나가는데 거리가 더 멀다(우선순위1)
						q.push({ x, y,d + 1 });
				}
				else
				{
					if (arr[x][y] <= size)//지나갈수 있다
					{

						if (size > arr[x][y])
						{
							//사이즈가 작다.
							if (d + 1 == mini)//동일 선상이다.우선 순위
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
							//사이즈가 같다.
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
			//업데이트
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