#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> ary;
int dp[100001][5][5];

int get_cost(int from, int to) {
	if (from == 0)return 2;
	else if (from == to)return 1;
	else if ((from == 2 && to == 4) || (from == 4 && to == 2) || 
		(from == 1 && to == 3) || (from == 3 && to == 1)) return 4;
	else return 3;
}

int solve(int cnt, int left, int right) {
	if (cnt == ary.size()) return 0;
	if (dp[cnt][left][right] != -1) return dp[cnt][left][right];

	int target = ary[cnt];

	// 왼발을 움직이는 경우 (오른발과 겹치지 않아야함)
	int move_left = 1e9;
	if (target != right) {
		move_left = solve(cnt + 1, target, right) + get_cost(left, target);
	}
	// 오른발을 움직이는 경우 (왼발과 겹치지 않아야함)
	int move_right = 1e9;
	if (target != left) {
		move_right = solve(cnt + 1, left, target) + get_cost(right, target);
	}
	return dp[cnt][left][right] = min(move_left, move_right);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int i = 0;
	while (true) {
		int x;
		cin >> x;
		
		if (x == 0)break;
		else {
			ary.push_back(x);
			i++;
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0);
	
}