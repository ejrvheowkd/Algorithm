#include <iostream>
#include <stack>

using namespace std;

string s, result;
int possible = 0;
stack <char> rest;
void caculate(int i);
int main()
{
	cin >> s;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (65 <= s[i] && 90 >= s[i])
		{
			result.push_back(s[i]);
		}
		else
		{
			if (s[i] == '(')
			{
				rest.push('(');
			}
			else
			{
				caculate(i);
			}
		}
	}
	int size = rest.size();
	for (int i = 0; i < size; i++)
	{
		result.push_back(rest.top());
		rest.pop();
	}
	cout << result << endl;
	return 0;
}
void caculate(int i)
{
	if (rest.empty())
	{
		rest.push(s[i]);
		return;
	}
	if (s[i] == ')')
	{
		while (true)
		{
			char tmp = rest.top();
			rest.pop();
			if (tmp == '(')
				break;
			else
				result.push_back(tmp);
		}
	}
	else
	{
		char tmp = rest.top();
		if (s[i] == '+' || s[i] == '-')
		{
			if (tmp == '(')
			{
				rest.push(s[i]);
			}
			else
			{
				while (true)
				{
					if (rest.empty()||rest.top() == '(' )
					{
						rest.push(s[i]);
						break;
					}
					else
					{
						result.push_back(rest.top());
						rest.pop();
					}
				}
			}
		}
		else
		{
			while (true)
			{
				if (rest.empty())
				{
					rest.push(s[i]);
					break;
				}
				if (rest.top() == '*' || rest.top() == '/')
				{
					result.push_back(rest.top());
					rest.pop();
				}
				else
				{
					rest.push(s[i]);
					break;
				}				
			}
		}
	}
}