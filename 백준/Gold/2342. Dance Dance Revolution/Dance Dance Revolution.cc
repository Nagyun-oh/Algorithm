#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int ary[100001];
int dp[100001][5][5]; // dp[지시사항][왼쪽][오른쪽]
int n;

int get_cost(int from, int to) {
	if (from == 0)return 2;
	else if (from == to) return 1;
	else if ((from == 2 && to == 4) || (from == 4 && to == 2)
		|| (from == 1 && to == 3) || (from == 3 && to == 1)) return 4;
	else return 3;
}

int solve(int cmd, int left, int right) {
	if (cmd == n)return 0;
	if (dp[cmd][left][right] != 0) return dp[cmd][left][right];

	int target = ary[cmd];

	int move_left = 1e9;
	if (target != right) {
		move_left = solve(cmd + 1, target, right) + get_cost(left, target);
	}

	int move_right = 1e9;
	if (target != left) {
		move_right = solve(cmd + 1, left, target) + get_cost(right, target);
	}

	return dp[cmd][left][right] = min(move_left, move_right);

}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	while (true) {
		int val; cin >> val;
		if (val == 0)break;
		else ary[n++] = val;
	}

	memset(dp, 0, sizeof(dp));

	cout << solve(0, 0, 0);
}