#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M; // 3<= N,M <=300
int sea[301][301];
int visited[301][301];
int melt[301][301];
int year;
vector<pair<int, int>> icePos;

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void Melt() {

	for (auto a : icePos) {
		int curY = a.first;
		int curX = a.second;

		if (sea[curY][curX] == 0)continue;

		int cnt = 0;

		for (int i = 0; i < 4; i++) {
			int ny = curY + direct[i][0];
			int nx = curX + direct[i][1];

			if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1) continue;

			if (sea[ny][nx] == 0)cnt++;
		}
		
		melt[curY][curX] = cnt;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sea[i][j] -= melt[i][j];
			if (sea[i][j] < 0) sea[i][j] = 0;
		}
	}

}

void bfsForCheck(int y,int x) {

	queue<pair<int, int>>q;
	q.push({ y,x });

	visited[y][x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny < 0 || ny>N - 1 || nx<0 || nx>M - 1)continue;

			if (!visited[ny][nx] && sea[ny][nx] > 0) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
			
		}
	}

}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> sea[i][j]; // 0 <= sea[i][j] <= 10
			if (sea[i][j] > 0)icePos.push_back({ i,j });
		}
	}
	
}

void solve() {

	while (true) {

		// 0) 빙산 녹이기 알고리즘 수행마다 visited 배열값을 모두 0으로 초기화
		memset(visited, 0, sizeof(visited)); 

		// 1) 빙산 덩어리 개수 세기
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && sea[i][j] > 0) {
					bfsForCheck(i,j);
					cnt++;
				}
			}
		}

		/* 2) 값 체크 */

		// 2-1) 두 덩어리 이상으로 나눠졌으면 출력후 종료
		if (cnt >= 2) {
			cout << year;
			break;
		}
		else if (cnt == 0 ) {
			// 2-2) 다 녹았는데, 두 덩어리 이상으로 분리안됐으면 0 출력
			cout << 0;
			break;
		}
		else {
			/* 3) 빙산 녹이기 알고리즘 수행*/
			Melt();
		}

		year++; // 시간(년) 증가
	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	input();
	solve();
	
}