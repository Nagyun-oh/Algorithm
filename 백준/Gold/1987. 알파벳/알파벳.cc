#include <iostream>
#include <vector>
using namespace std;

int direct[4][2] = {
	-1,0, // 상
	1,0,  // 하
	0,-1, // 좌
	0,1   // 우
};

int R, C;
char board[21][21];
int visited[26];
int ans = 0;

void dfs(int y, int x, int cnt) {

	ans = max(ans, cnt);

	// 상 하 좌 우
	for (int i = 0; i < 4; i++) {
		int dy = y + direct[i][0];
		int dx = x + direct[i][1];

		if (dy < 0 || dy >= R || dx < 0 || dx >= C)continue;
		int idx = board[dy][dx] - 'A';

		if (!visited[idx]) {
			visited[idx] = 1;
			dfs(dy, dx, cnt + 1);
			visited[idx] = 0;
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin>>board[i];
	}

	visited[board[0][0] - 'A'] = 1; // 좌측 상단에서 시작하니까 방문처리하고,
	dfs(0, 0, 1); // cnt = 1로 시작
	cout << ans;

}