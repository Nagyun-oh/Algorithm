#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100001
int arr[2][MAX];
int dp[2][MAX];
int n;

void solve()
{
	// 초기값 지정
	dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
	dp[0][1] = arr[0][1] + arr[1][0]; dp[1][1] = arr[1][1] + arr[0][0];

	// 테이블 채우기
	for (int i = 2; i < n; i++) {
		dp[0][i] = max({ dp[1][i - 2], dp[1][i - 1], dp[0][i - 2] }) + arr[0][i];
		dp[1][i] = max({ dp[0][i - 2],dp[0][i - 1],dp[1][i - 2] }) + arr[1][i];
	}

	int res = max(dp[0][n - 1], dp[1][n - 1]);
	cout << res << '\n';

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; 
	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin>> arr[i][j];
			}
		}
		// 알고리즘
		solve();
	}

}