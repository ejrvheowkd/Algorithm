/*#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

bool compare(const pii& a, const pii& b)
{
	if (a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
int main()
{
	int cost[10] = { 6,2,5,5,4,5,6,3,7,6 };
	vector<pii>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(pii{ cost[i],i });
	}
	sort(v.begin(), v.end(),compare);
	int T,flag=0;
	cin >> T;
	while (T--)
	{
		vector <int> result;
		int n,now=9;
		cin >> n;
		while (1)
		{
			if (n - v[0].first < 0)
				break;
			result.push_back(v[0].second);
			n -= v[0].first;
		}
		for(int i=0;i<result.size();i++)
		{
			while (1)
			{
				if (n - (cost[now]-2) < 0)
					now--;
				else if (now == 1)
					break;
				else
				{
					
					n -= cost[now]-2;
					result[i] = now;
					break;
				}
			}
		}
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
		cout << endl;
	}
	return 0;
}*/

/*3번*/
#include <iostream>
#include <algorithm>
using namespace std;
int check[101][51] = { 0 },sum[101];

int N, M, list[101][51], arr[101];
const int MIN = -2000000000;
int dp(int now, int num)
{
	if (num == 0)
		return 0;

	if (now > N|| num < 0)
		return MIN;
	
	int &ret = list[now][num];

	if (ret!= MIN)
		return list[now][num];
	//안먹고 다음
	ret = -100000007;
	ret = max(ret, dp(now+1, num));
	//i번째까지먹고 다다음
	for (int i = 0; i+now <= N; i++)
	{
		ret = max(ret, dp(i+now+2, num-1)+sum[now+i]-sum[now-1]);
	}
	return ret;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i <=N; i++)
	{
		for (int j = 0; j <= M; j++)
			list[i][j] = MIN;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i-1]+arr[i];
	}
	cout<<dp(1, M);
	return 0;
}

/*차 코딩테스트



알고리즘 1번 : 7 - segment(codeforces.com / problemset / problem / 1295 / A)

알고리즘 2번 : 색종이 관련 문제

알고리즘 3번 : 구간 나누기

SQL : 학생들의 성적 평균 비슷한 문제..

웹 : To Do List



2차 코딩테스트



알고리즘 1번 : 연속합 구하기(boj.kr / 1912)

알고리즘 2번 : union - find or bfs / dfs(boj.kr / 10216)

알고리즘 3번 : 스위핑

SQL : 게시판에서 누가 가장 많이 들었는지 상위 몇명

웹 : 로그인 구현

*/