#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int area[101][101];
int temp[101][101];
int visited[101][101];
int cnt = 0;

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void bfs(int y, int x,int height) {

	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny<0 || ny>n - 1 || nx<0 || nx>n - 1||visited[ny][nx]) continue;

			if (area[ny][nx] > height) {
				cnt++;
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int maxHeight = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
			if (maxHeight < area[i][j]) {
				maxHeight = area[i][j];
			}
		}
	}

	vector<int> res;

	int final_Max = 1;

	for (int h = 1; h < maxHeight; h++) {
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (!visited[i][j] && area[i][j] > h) {
					cnt = 0;
					bfs(i, j, h);
					res.push_back(cnt);
				}

			}
		}

		if (final_Max < res.size()) {
			final_Max = res.size();
		}
		res.clear();
	}


	cout << final_Max;

}