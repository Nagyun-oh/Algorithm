#include <iostream>
#include <queue>

using namespace std;

int M, N;
int box[1001][1001];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
queue<pair<int, int>>q;

void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();
		// 하루 추가
		for (int i = 0; i < 4; i++) {
			int dy = y + direct[i][0];
			int dx = x + direct[i][1];

			if (dy >= 0 && dy < N && dx >= 0 && dx < M) {
				if (box[dy][dx] == 0) {
					box[dy][dx] = box[y][x] + 1; // 하루 갱신 
					q.push({ dy,dx }); // 익힌 토마토 넣기
				}
			}

		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)q.push({ i,j });
		}
	}

	BFS();

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else {
				if (max < box[i][j]) max = box[i][j]; // 날짜 갱신
			}
		}
	}

	cout << max - 1;


	return 0;
}