#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N; // 1<= C <=1000, 1<= N <=20
int cost[21], client[21];
int dp[100001]; // 1원 ~ 100,000원 별 최대 고객 수

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	// input
	cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i] >> client[i];
	}

	// alg
	for (int i = 1; i <= N; i++) {
		// 홍보비가 cost[i]일 때,
		for (int j = 1; j <= 100000; j++) {
			// j는 현재 쓸 수 있는 돈
			// 돈이 남는 경우
			if (j >= cost[i]) {
				dp[j] = max(dp[j], dp[j - cost[i]] + client[i]);
			}
		}
	}

	for (int i = 1; i <= 100000; i++) {
		if (dp[i] >= C) {
			cout << i;
			break;
		}
	}


}