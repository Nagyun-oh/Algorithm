#include <iostream>
#include <algorithm>
using namespace std;

void init();
void solve();
int x;
int dp[1000000];

void init()
{
	cin >> x;
}

// 연산은 세가지
// 1. x가 3으로 나누어 떨어지면 , 3으로 나눈다.
// 2. x가 2로 나누어 떨어지면, 2로 나눈다.
// 3. 1을 뺀다.
// 연산을 사용하는 횟수의 "최솟값" -> 연산의 우선순위 정하기?
// 규칙성을 찾아서, 점화식을 도출하는 DP문제이다.

void solve()
{
	for (int i = 2; i <= x; i++)
	{
		// 1을 뺸다.
		dp[i] = dp[i - 1] + 1;

		//  2로 나누어지면
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		// 3으로 나누어지면
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	
	cout << dp[x];

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