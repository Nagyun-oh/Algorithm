#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int ary[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
	}

	// 1자리인 경우
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
	}
	
	// 2자리인 경우
	for (int i = 1; i <= N-1; i++) {
		if (ary[i] == ary[i + 1]) dp[i][i + 1] = 1;
	}

	// 3자리 이상
	for (int len = 3; len <= N; len++) {
		for (int start = 1; start <= N -len+1; start++) {
			int end = start + len - 1;

			if (ary[start] == ary[end] && dp[start+1][end-1] == 1) {
				dp[start][end] = 1;
			}

		}
	}

	int s, e;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}


}