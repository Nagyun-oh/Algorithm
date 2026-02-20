#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int sharkSize = 2;
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

struct fishInfo {
	int y;
	int x;
	int dist;
};

int sea[21][21];
int visited[21][21];

int shark_y, shark_x;

bool cmp(fishInfo a, fishInfo b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	else if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

fishInfo findTarget() {

	memset(visited, 0, sizeof(visited));

	vector<fishInfo> canEatFish;

	queue<fishInfo> q;
	q.push({ shark_y,shark_x ,0}); //  상어 위치 넣기
	visited[shark_y][shark_x] = 1;

	int minDist = 1e9;

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dist = q.front().dist;

		q.pop();

		if (dist > minDist) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;

			// 1. 이동할 수 있는 경우
			if (sharkSize >= sea[ny][nx]) {

				visited[ny][nx] = 1;
				q.push({ ny,nx,dist + 1 });

				// 2. 먹을 수 있는 경우
				if (sharkSize > sea[ny][nx] && sea[ny][nx] >= 1) {
					minDist = dist + 1;
					canEatFish.push_back({ ny,nx,dist+1 });
					
				}
			}

		}

	}

	if (canEatFish.empty()) return { -1,-1,-1 }; // 먹을 수 있는 생선이 없는 경우

	sort(canEatFish.begin(), canEatFish.end(), cmp);

	return canEatFish[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sea[i][j];

			if (sea[i][j] == 9) {
				shark_y = i;
				shark_x = j;
				sea[i][j] = 0;
			}
		}
	}

	int totalTime = 0;
	int eatCount = 0;

	while (true) {

		// 1. 먹을 수 있는 생선 정보
		fishInfo target = findTarget();

		// 2. 먹을 수 있는 생선 없는 경우 종료
		if (target.y == -1)break;

		// 3. 아기 상어가 생선 먹고 위치 및 시간 갱신
		shark_y = target.y;
		shark_x = target.x;
		sea[shark_y][shark_x] = 0;
		totalTime += target.dist;
		eatCount++;

		// 4. 아기 상어 크기 갱신
		if (eatCount == sharkSize) {
			sharkSize++;
			eatCount = 0;
		}
	}

	cout << totalTime;

}