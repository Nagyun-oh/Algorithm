#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int r, c, d; //  처음에 로봇 청소기가 있는 좌표 (r,c) 와 방향 d
int room[51][51];
int visited[51][51];
int cnt = 0;

struct info {
	int y;
	int x;
	int dir; // 방향
};

int direct[4][2] = {
	-1,0, // 북
	0,1,  // 동
	1,0, // 남
	0,-1   // 서
};

void bfs() {

	queue<info> q;
	q.push({ r,c,d }); // 처음 로봇청소기의 좌표 및 방향 저장
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		int flag = 0;

		// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (room[y][x] == 0 && !visited[y][x]) {
			visited[y][x] = true;
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1)continue;

			// 청소할 수 있는데, 아직 청소하지 않은 칸이 있는지 확인
			if (!visited[ny][nx] && room[ny][nx] == 0) {
				flag = 1; // flag ==1 이면, 현재 칸 기준 주변 4칸에청소할 수 있는 칸이 있는것.
				break;
			}
		}

		// 2. 현재 칸 기준으로 주변 4칸이 모두 청소된 경우
		if (flag == 0) {
			// 1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면, 한 칸 후진하고 1번으로 돌아간다.
			// 2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진 할 수 없다면 작동을 멈춘다.
			int ny = 0,nx = 0;
		
			if (dir == 0) {
				ny = y + 1;
				nx = x;
			}
			else if (dir == 1) {
				ny = y;
				nx = x - 1;

			}
			else if (dir == 2) {
				ny = y - 1;
				nx = x;
			}
			else if (dir == 3) {
				ny = y;
				nx = x + 1;
			}

			// 2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진 할 수 없다면 작동을 멈춘다.
			if (ny<0 || ny>n - 1 || nx<0 || nx>m - 1
				|| room[ny][nx] == 1)break;
			
			// 1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면, 한 칸 후진하고 1번으로 돌아간다.
			q.push({ ny,nx ,dir});
			continue;
		}

		// 3. 현재 칸 기준으로 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
		if (flag == 1) {

			// 1) 반시계 방향으로 90도 회전 한다.
			dir = (dir + 3) % 4;

			// 2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한칸 전진한다.
			int ny, nx;
			
			if (dir == 0) {
				ny = y - 1;
				nx = x;

			}
			else if (dir == 1) {
				ny = y;
				nx = x + 1;

			}
			else if (dir == 2) {
				ny = y + 1;
				nx = x;

			}
			else if (dir == 3) {
				ny = y;
				nx = x - 1;
			}

			if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && room[ny][nx] == 0) {
				q.push({ ny,nx ,dir });
			}
			else {
				q.push({ y,x,dir });
				continue;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	
	bfs();// 로봇 청소기 작동 시작

	cout << cnt; // 로봇 청소기가 작동을 멈출때까지 청소하는 칸의 개수 출력
}