#include <iostream>
#include <vector>
using namespace std;

string str;
int ary[9][9];
vector<pair<int, int>> v;
bool isEnd = false;
int len;

bool check(int y, int x, int value) {

	for (int i = 0; i < 9; i++) {
		if (ary[y][i] == value)return false; // 열 검사
		if (ary[i][x] == value)return false; // 행 검사
	}

	int part_y = y / 3;
	int part_x = x / 3;
	part_y *= 3;
	part_x *= 3;

	for (int i = part_y; i < part_y + 3; i++) {
		for (int j = part_x; j < part_x + 3; j++) {
			if (ary[i][j] == value)return false;
		}
	}

	return true;
}


void dfs(int cur) {

	if (isEnd)return;

	if (cur == len) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << ary[i][j];
			}
			cout << '\n';
		}
		isEnd = true;
	}
	else {
		int ny = v[cur].first;
		int nx = v[cur].second;

		for (int i = 1; i <= 9; i++) {

			if (check(ny, nx, i)) {
				// 백트래킹
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


	/* 입력 */
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			ary[i][j] = str[j] - '0';

			if (ary[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	len = v.size();

	dfs(0);

}