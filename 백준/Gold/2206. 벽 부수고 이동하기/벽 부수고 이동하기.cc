//6:39 ~ 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ary[1001][1001];

int visited[1001][1001][2]; // vistied[y][x][벽 부숨 여부] : 0이면 안 부숨, 1이면 부숨

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

int n, m;
int cnt;
int posY, posX;

struct info {
	int y;
	int x;
	int wall;
};

void bfs() {

	queue<info> q;
	q.push({ 1,1 ,0});  // (1,1)에서 시작
	visited[1][1][0] = 1; // 시작점 포함 거리 1

	while (!q.empty()) {
		info cur = q.front();
		int y = cur.y;
		int x = cur.x;
		int wall = cur.wall;
		q.pop();
		
		// N,M에 도착하면 종료
		if (y == n && x == m) {
			cout << visited[y][x][wall];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];
		
			if (ny < 1 || ny>n|| nx < 1 || nx>m)continue; // 예외처리

			// 1. 다음 칸이 벽이 아닌 경우
			if (ary[ny][nx] == 0&&visited[ny][nx][wall]==0) {
				visited[ny][nx][wall] = visited[y][x][wall] + 1; // 경로 증가
				q.push({ ny,nx,wall });
			}

			// 2. 다음 칸이 벽이고, 아직 벽을 부순적 없는 경우
			if (ary[ny][nx] == 1 && visited[ny][nx][1] == 0 && wall==0) {
				visited[ny][nx][1] = visited[y][x][wall] + 1;
				q.push({ ny,nx,1 });
			}
			
		}

	}

	// 불가능할 경우 -1 출력
	cout << -1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 1; j <= m; j++) {
			ary[i][j] = str[j - 1] - '0';
		}
	}

	bfs();

}