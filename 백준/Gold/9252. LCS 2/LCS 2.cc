#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int m = str1.size();
	int n = str2.size();


	/* LCS 최대 길이 구하기 */
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			if (str1[i - 1] == str2[j - 1]) 
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else 
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}


	/* 역순 으로 구하기 */
	int i = m;
	int j = n;
	string res;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			res += str1[i - 1];
			i--;
			j--;
		}
	}

	reverse(res.begin(), res.end());

	cout << dp[m][n] << '\n';
	cout << res;

}