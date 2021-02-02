#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <string> s;
string tmp;
int n;
int check[101];
bool caculate(int e)
{
	for (int i = 0; i < tmp.length(); i++)
	{

		if (i != 0 && check[i - 1] == -1)
		{
			continue;
		}
		else if (i == 0||check[i-1]==1)
		{

			for (int j = 0; j < n; j++)
			{
				bool flag = true;

				if (i + s[j].length() > tmp.length())
					continue;
				else
				{
					for (int k = 0; k < s[j].length(); k++)
					{
						if (tmp[i + k] != s[j][k])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						check[i + s[j].length() - 1] = 1;
					}
				}
				
			}
			
		}
	}
	if (check[tmp.length()-1] == 1)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{
	cin >> tmp;
	cin>> n;
	memset(check, -1, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		s.push_back(x);
	}
	cout << caculate(0) << endl;

	return 0;
}