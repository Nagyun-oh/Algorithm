#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int r, c, d;
int room[51][51];
int visited[51][51];
int cnt;

struct info {
	int y;
	int x;
	int dir;
};

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void bfs(int r,int c , int d) {

	queue<info> q;
	q.push({ r,c,d });
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();

		int flag = 0;

		// 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
		if (room[y][x]==0 && !visited[y][x]) {
			cnt++;
			visited[y][x] = true;
		}

		//  2번/3번 상태 결정해주기
		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1)continue;

			// 현재 칸 기준으로 주변에 청소할 칸이 있는 경우 flag = 1;
			if (room[ny][nx] == 0 && !visited[ny][nx]) {
				flag = 1;
				break;
			}
		}

		// 2. 현재 칸의 주변 칸이 모두 청소된 경우
		if (flag == 0) {
			int ny = 0, nx = 0;
			// 1) 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
			if (dir == 0) {
				// 북
				ny = y + 1;
				nx = x;
			}
			else if (dir == 1) {
				// 동
				ny = y;
				nx = x - 1;
			}
			else if (dir == 2) {
				// 남
				ny = y - 1;
				nx = x;
			}
			else if (dir == 3) {
				// 서
				ny = y;
				nx = x + 1;
			}

			if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1)continue;

			if (room[ny][nx] == 0) {
				q.push({ ny,nx,dir });
				continue;
			}
			// 2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
			else if (room[ny][nx] == 1) {
				break;
			}

		}
		// 3. 현재 칸의 주변칸 중 청소되지 않은 빈 칸이 있는 경우
		else if (flag == 1) {
			int ny=0, nx = 0;

			// 1) 반시계 방향으로 90도 회전한다.
			dir = (dir + 3) % 4;

			// 2) 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
			if (dir == 0) {
				// 북
				ny = y - 1;
				nx = x;
			}
			else if (dir == 1) {
				// 동
				ny = y;
				nx = x + 1;

			}
			else if (dir == 2) {
				// 남
				ny = y + 1;
				nx = x;	
			}
			else if (dir == 3) {
				// 서
				ny = y;
				nx = x - 1;	
			}
			
			if (ny<0 || ny>N - 1 || nx<0 || nx>M - 1)continue;
			
			if (!visited[ny][nx] && room[ny][nx] == 0) {
				q.push({ ny,nx,dir });
			}
			// 3) 1번으로 돌아간다.
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

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}

	bfs(r,c,d);

	cout << cnt;

}