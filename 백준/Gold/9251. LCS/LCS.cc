#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int m = str1.size(); 
	int n = str2.size();

	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0)); // m+1 x n+1 , initialize with 0

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	cout << dp[m][n];

}