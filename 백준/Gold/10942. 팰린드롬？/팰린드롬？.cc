#include <iostream>
using namespace std;

int N, M;
int S, E;

int ary[2001];
int dp[2001][2001]; // [S,E] 구간이 팰린드롬인지 저장하는 배열

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
	}

	/* algorithm : dp with 메모이제이션 */

	// 길이가 1인경우
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}

	// 길이가 2인 경우
	for (int i = 1; i <= N - 1; i++) {
		if (ary[i] == ary[i + 1])dp[i][i + 1] = 1;
	}

	// 길이 >=3
	for (int len = 3; len <= N; len++) {
		for (int start = 1; start <= N - len + 1; start++) {
			int end = start + len - 1;

			if (ary[start] == ary[end] && dp[start + 1][end - 1] == 1) {
				dp[start][end] = 1;
			}
		}
	}

	/* ===================  */

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}

}