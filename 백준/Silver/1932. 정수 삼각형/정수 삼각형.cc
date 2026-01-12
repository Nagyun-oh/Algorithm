#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501] = { 0, };
int dp[501][501] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int res = dp[n][1];

	for (int i = 2; i <= n; i++) {
		res = max(res, dp[n][i]);
	}

	cout << res << '\n';


}

