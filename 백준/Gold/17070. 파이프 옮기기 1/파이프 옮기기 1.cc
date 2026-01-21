#include <iostream>
using namespace std;

int n;
int home[17][17];
int dp[17][17][3]; // dp[y][x][dir] : 파이프의 끝점이 (y,x)에 있고 dir상태일 때 경우의수
// dir : 0= 가로, 1=세로, 2=대각

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++)cin >> home[y][x];
	}

	// 시작 상태 : (1,1)-(1,2) 가로로 놓여있고 끝점이 1,2
	if (home[1][1] == 0 && home[1][2] == 0)dp[1][2][0] = 1;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {

			if (home[y][x] == 1)continue; // 끝점 자체가 벽이면 불가

			// 1. 가로로 끝나는 경우
			if (x - 1 >= 1 && home[y][x] == 0) {
				dp[y][x][0] += dp[y][x - 1][0];
				dp[y][x][0] += dp[y][x - 1][2];
			}

			// 2. 세로로 끝나는경우
			if (y - 1 >= 1 && home[y][x] == 0) {
				dp[y][x][1] += dp[y - 1][x][1];
				dp[y][x][1] += dp[y - 1][x][2];
			}

			// 3. 대각으로 끝나는경우
			if (y - 1 >= 1 && x - 1 >= 1) {
				if (home[y - 1][x] == 0 && home[y][x - 1] == 0 && home[y][x] == 0) {
					dp[y][x][2] += dp[y - 1][x - 1][0];
					dp[y][x][2] += dp[y - 1][x - 1][1];
					dp[y][x][2] += dp[y - 1][x - 1][2];
				}
			}

		}
	}

	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];

}