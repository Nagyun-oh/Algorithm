#include <iostream>
#include <algorithm>
using namespace std;

int H;
int Y;
void init();
void solve();


int dp[16] = { 0, };

void init()
{
	cin >> H >> Y;
}

void solve()
{
	// 초기값 설정 , 5년이면 0 원
	dp[5] = H;
	
	// 점화식 
	for (int i = 6; i <= Y+6; i++)
	{
		dp[i] = max(dp[i - 5] *1.35, max(dp[i - 1]*1.05, dp[i - 3]*1.20));
	}

	cout << dp[Y+5];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	

	init();
	solve();

	return 0;
}