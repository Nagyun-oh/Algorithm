#include <iostream>

using namespace std;

void init();
void solve();

int n;
int dp[1001];

void init()
{
	cin >> n;
}

void solve()
{
	//초기값 구성할때, dp[3]값을 잘못구해서 답이 안나오는 거였다. 담에는 명확한
	// 부분까지만 초기값을 구하자
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2]*2;
		dp[i] = dp[i] % 10007;
	}

	cout<< dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	init();
	solve();

}