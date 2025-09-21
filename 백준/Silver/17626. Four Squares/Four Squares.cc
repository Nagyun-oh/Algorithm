#include <iostream>
#include<algorithm>
using namespace std;

int dp[50001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	

	// dp 문제인데 쉽지않네 
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[1]; // 초기 비교값 

		for (int j = 2; j*j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1); // 최소개수 갱신 dp[j*j] = 1
		}
		
	}
	
	
	cout << dp[n];

}