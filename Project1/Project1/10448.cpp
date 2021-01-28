#include <iostream>

using namespace std;

typedef struct {
	int num;
	int s;
	int b;
}INFO;
int main()
{
	int N,cnt=0;
	INFO arr[100];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].num >> arr[i].s >> arr[i].b;
	}
	for (int i = 123; i <= 987; i++)
	{
		int one = i% 10,ten=(i/10)%10, thousand=i/100;
		int flag=1;
		if (one != ten && one != thousand && ten != thousand&&ten!=0&&one!=0)
		{
			for (int j = 0; j < N; j++)
			{
				int tmp = arr[j].num;
				int first= tmp % 10,second= (tmp / 10) % 10,thrid = tmp / 100;
				int s=0, b=0;
				if (one == first)
					s++;
				else if (first == ten || first == thousand)
					b++;
				if (second == ten)
					s++;
				else if (second == one || second == thousand)
					b++;
				if (thrid == thousand)
					s++;
				else if (thrid == one || thrid == ten)
					b++;
				if (arr[j].b != b || arr[j].s != s)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}