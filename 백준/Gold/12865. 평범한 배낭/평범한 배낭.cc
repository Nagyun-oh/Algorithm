#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k; // 물품수 , 최대 무게

	vector<int> w(n + 1,0);
	vector<int> v(n + 1,0);

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i]; // 각 물건의 무게, 가치 입력받기
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= w[i])dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
			else dp[i][j] = dp[i - 1][j]; // j<w[i]
		}
	}
	cout << dp[n][k];

}