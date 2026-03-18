#include <iostream>
#include <vector>
using namespace std;

int ary[9][9];
vector<pair<int, int>> pos;
int isEnd = false;

bool check(int y,int x,int value) {

	for (int i = 0; i < 9; i++) {
		if (value == ary[y][i])return false;
		if (value == ary[i][x])return false;
	}

	int part_y = y / 3;
	int part_x = x / 3;
	part_y *= 3;
	part_x *= 3;

	for (int i = part_y; i < part_y + 3; i++) {
		for (int j = part_x; j < part_x + 3; j++) {
			if (value == ary[i][j])return false;
		}
	}

	return true;

}

void dfs(int cur) {

	if (isEnd)return;
	else if (cur == pos.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << ary[i][j];
			}
			cout << '\n';
		}
		isEnd = true;
	}
	else {
		int ny = pos[cur].first;
		int nx = pos[cur].second;

		for (int i = 1; i <= 9; i++) {
			if (check(ny, nx, i)) {
				ary[ny][nx] = i;
				dfs(cur + 1);
				ary[ny][nx] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			ary[i][j] = str[j] - '0';
			if (ary[i][j] == 0)pos.push_back({ i,j });
		}
	}

	dfs(0);

}