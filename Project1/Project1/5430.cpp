#include <iostream>

using namespace std;

int main()
{
	/*
		�ʱ�ȭ �Ǽ� , �ҽ� �ۼ� �� ���̳� �Ӹ��� �ù����̼��ϴ� ������ ���̰� 
		�ݺ����� �ۼ��� �־� ����ó���� ���־��� �� �׷� ���� �ٸ� ������ �ִ��� �����غ��� �������̱�
	*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string p, list;
		int N,arr[100001] = { 0 };
		cin >> p >> N >> list;
		for(int i=1,k=0;;i++, k++)
		{
			if (list[i] == ']'||i>=list.length())
				break;
			int sum = 0;
			while (1)
			{
				if (list[i] != ',' &&list[i]!=']')
				{
					sum = sum * 10 + list[i] - '0';
					
				}
				if(list[i+1]==','||list[i+1]==']')
					break;
				i++;
			}
			arr[k] = sum;
		}
		int s = 0,e=N-1,flag=0; // flag ==0�̸� �տ��� ���� ����(s++) flag==1�̸� �ڿ��� ���� �A��(e--).
		int cnt = 0;
		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R')
				flag =(flag+ 1)%2;
			else
			{
				if (cnt == N)
				{
					flag = 3;
					break;
				}
				if (flag == 0)
				{
					s++;
				}
				else
				{
					e--;
				}
				cnt++;
			}
		}
		if (flag == 3)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << '[';

			if (flag == 0)
			{
				for (int i = s; i <= e; i++)
				{
					cout << arr[i];
					if (i != e)
						cout << ',';
				}
			}
			else
			{
				for (int i = e; i >= s; i--)
				{
					cout << arr[i];
					if (i != s)
						cout << ',';
				}
			}
			cout << ']' << endl;

		}
	}
	return 0;
}