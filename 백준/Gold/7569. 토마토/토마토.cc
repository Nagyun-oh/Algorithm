#include <iostream>
#include <queue>
using namespace std;


int ans = 0;
int fruit[101][101][101];
int visited[101][101][101];
int direct[6][3] = {
	{-1,0,0}, 
	{1,0,0},
	{0,-1,0},
	{0,1,0},
	{0,0,-1},
	{0,0,1}
};
queue <pair<pair<int, int>, int>>q;
int M, N, H;

void bfs() {

	while (!q.empty()) {

		int yy = q.front().first.first;
		int xx = q.front().first.second;
		int zz = q.front().second;
		q.pop();
		//하루 갱신 ( 인접한 6개의 토마토 익히기)
		for (int i = 0; i < 6; i++) {
			int dy = yy + direct[i][0];
			int dx = xx + direct[i][1];
			int dz = zz + direct[i][2];

			if (dy >= 0 && dy < N && dx >= 0 && dx < M && dz >= 0 && dz < H) {
				if (fruit[dz][dy][dx] == 0) {
					fruit[dz][dy][dx] = fruit[zz][yy][xx] + 1; 
					q.push({ {dy,dx},dz });
				}
			}
		}








	}



}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> fruit[k][i][j];
				if (fruit[k][i][j] == 1)q.push({{ i,j }, k});
			}
		}
	}

	bfs();
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (fruit[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				else {
					if (fruit[k][i][j] > ans)ans = fruit[k][i][j];
				}
			}
		}
	}
	cout << ans - 1;

}