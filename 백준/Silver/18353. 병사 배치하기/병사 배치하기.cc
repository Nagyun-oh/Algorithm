#include <iostream>
#include <vector>
using namespace std;

int N;

int ary[2001];
int dp[2001];

void init();
void solve();

void init()
{
	cin >> N;
	int x;
	for (int i = 1; i <= N; i++)
	{
		cin >> ary[i];
		
	}
}

void solve()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (ary[j] > ary[i]) // 내림차순일때마다 길이 갱신
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int max_value = 0;
	for (int i = 1; i <= N; i++)max_value = max(dp[i], max_value);
	
	

	cout << N - max_value;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	solve();

}