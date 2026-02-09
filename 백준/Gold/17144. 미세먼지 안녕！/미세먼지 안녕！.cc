#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, T;
int ary[51][51];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

vector<pair<int, int>> airCleanPos;

void spread() {
	int tmp[51][51] = { 0 };

	//공기청정기 위치 유지
	for (auto p : airCleanPos) {
		tmp[p.first][p.second] = -1;
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (ary[y][x] <= 0) continue;

			int amount = ary[y][x] / 5;
			int cnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + direct[i][0];
				int nx = x + direct[i][1];

				if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
				if (ary[ny][nx] == -1)continue;

				tmp[ny][nx] += amount;
				cnt++;
			}
			tmp[y][x] += ary[y][x] - amount * cnt;
		}
	}

	memcpy(ary, tmp, sizeof(ary));
}

void clean() {
	int top = airCleanPos[0].first;
	int bottom = airCleanPos[1].first;

	// 위쪽 (반시계)
	for (int i = top - 1; i > 0; i--)ary[i][0] = ary[i - 1][0];
	for (int i = 0; i < C - 1; i++)ary[0][i] = ary[0][i + 1];
	for (int i = 0; i < top; i++)ary[i][C - 1] = ary[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--)ary[top][i] = ary[top][i - 1];
	ary[top][1] = 0;
	// 아래쪽 (시계)
	for (int i = bottom + 1; i < R - 1;i++ )ary[i][0] = ary[i + 1][0];
	for (int i = 0; i < C - 1; i++)ary[R - 1][i] = ary[R - 1][i + 1];
	for (int i = R - 1; i > bottom; i--)ary[i][C - 1] = ary[i - 1][C - 1];
	for (int i = C - 1; i > 1;i-- )ary[bottom][i] = ary[bottom][i - 1];
	ary[bottom][1] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> ary[i][j];
			if (ary[i][j] == -1)airCleanPos.push_back({ i,j });
		}
	}
	while (T--) {
		spread();
		clean();
	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (ary[i][j] >= 1) {
				sum += ary[i][j];
			}
		}
	}

	cout << sum;
}