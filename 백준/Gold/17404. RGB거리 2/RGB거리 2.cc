#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cost[1001][3];
int dp[1001][3];
int ans = 1e9;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int first = 0; first < 3; first++) {

		// 1. 초기화 : 첫번째 집 색 결정
		for (int i = 0; i < 3; i++) {
			if (i == first) dp[1][i] = cost[1][i];
			else dp[1][i] = 1e9;
		}

		// 2. 나머지 집 색 결정
		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		// 3. 마지막 집 색이 첫번째 집 색과 같은 경우를 제외하고 , 최소 비용 탐색
		for (int i = 0; i < 3; i++) {
			if (i == first)continue;
			else ans = min(ans, dp[N][i]);
		}
	}

	cout << ans;

}