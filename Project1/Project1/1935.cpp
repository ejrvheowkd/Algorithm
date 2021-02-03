#include <iostream>
#include <stack>

using namespace std;

//소문자 대문자 아스키코드
int main()
{
	int N, list[26] = { 0 },size;
	stack <double> st;
	string s;
	cin >> N>>s;
	size = s.length();
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			st.push(list[s[i] - 65]);
		}
		else
		{
			double one, two;
			one = st.top();
			st.pop();
			two = st.top();
			st.pop();
			if (s[i] == '-')
				st.push(two - one);
			else if (s[i] == '/')
				st.push(two / one);
			else if (s[i] == '+')
				st.push(two + one);
			else
				st.push(two * one);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top() << endl;
	return 0;
}