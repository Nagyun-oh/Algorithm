#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
int r[501];
int c[501];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> r[i] >> c[i];
	}

	// dist: 행렬 간의 거리
	for (int dist = 1; dist <= N; dist++) {
		for (int i = 1; i + dist <= N; i++) {
			int j = i + dist;
			dp[i][j] = INT_MAX;

			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k+1][j] + (r[i] * c[k] * c[j]);
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}

	cout << dp[1][N];	// 첫번째 행렬부터 N번째 행렬까지의 최소 연산 횟수

}