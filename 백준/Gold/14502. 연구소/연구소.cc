#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int ary[9][9];
int ans = 0;

vector<pair<int, int>> virusPos;
vector<pair<int, int>> zeroPos;
vector<int> res;

int visited[9][9];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void bfs() {

	// 벽 3개 세우기
	for (int i = 0; i < 3; i++) {
		ary[zeroPos[res[i]].first][zeroPos[res[i]].second] = 1;
	}

	memset(visited, 0, sizeof(visited)); // 매 케이스마다 방문배열 0으로 초기화

	queue<pair<int, int>> q;
	for (int i = 0; i < virusPos.size(); i++) {
		int y = virusPos[i].first;
		int x = virusPos[i].second;
		q.push({ y,x });
		visited[y][x] = 1;
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m|| visited[ny][nx] == 1 || ary[ny][nx] == 1)continue;

			q.push({ ny,nx });
			visited[ny][nx] = 1;
			
		}

	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ary[i][j] == 0 && !visited[i][j])cnt++;
		}
	}

	ans = max(cnt, ans);

	// 다시 벽 없애기
	for (int i = 0; i < 3; i++) {
		ary[zeroPos[res[i]].first][zeroPos[res[i]].second] = 0;
	}
}

void dfs(int idx) {

	if (res.size() == 3) {
		bfs();
		return;
	}

	for (int i = idx; i < zeroPos.size(); i++) {
		res.push_back(i);
		dfs(i + 1);
		res.pop_back();

	}
}


// 1. 벽을 3개씩 두어야함  (조합)
// 2. 벽 3개 둘때마다 탐색 (dfs)
// 3. 안전영역 최대값 갱신 (bfs)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ary[i][j];
			if (ary[i][j] == 0)zeroPos.push_back({ i,j });
			if (ary[i][j] == 2)virusPos.push_back({ i,j });
		}
	}

	dfs(0);
	cout << ans;

}