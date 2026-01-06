#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001] = { 0, };
int ary[1001] = { 0, };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (ary[i] < ary[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	sort(dp + 1, dp + n+1);

	cout << dp[n] + 1;

}