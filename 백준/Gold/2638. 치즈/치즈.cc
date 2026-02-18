#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

int n, m;
int ary[101][101];
int visited[101][101];
vector<pair<int, int>> chzPos;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ary[i][j];

			if (ary[i][j] == 1)chzPos.push_back({ i,j });
		}
	}
}

// 1. 외부공기와 내부공기를 구분해야함. ( bfs는 경계선 구분 가능)
void bfs() 
{
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visited[0][0] = 1;
	ary[0][0] = 2; // 외부공기는 2

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + direct[i][0];
			int nx = x + direct[i][1];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;

			if (!visited[ny][nx] && ary[ny][nx] != 1) {
				ary[ny][nx] = 2; // 외부공기로 설정
				visited[ny][nx] = 1; // 방문 처리 
				q.push({ ny,nx }); 
			}
		}

	}
}

void solve() {

	int time = 0;

	while (!chzPos.empty()) {

		if (chzPos.empty())break; // 0. 녹일 치즈 없으면 끝내기

		// 1. 외부공기 = 2, 내부공기 = 0 구분
		bfs(); 

		// 2. 녹일 수 있는 치즈와 녹일 수없는 치즈 구분
		vector<pair<int, int>> nextChzPos;
		vector<pair<int, int>> toMelt;

		for (auto p : chzPos) {

			int y = p.first;
			int x = p.second;
			int airCnt = 0;

			for (int i = 0; i < 4; i++) {
				int ny = y + direct[i][0];
				int nx = x + direct[i][1];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;

				if (ary[ny][nx] == 2)airCnt++;
			}

			if (airCnt >= 2)toMelt.push_back({ y,x }); // 녹여야할 치즈 위치 저장
			else nextChzPos.push_back({ y,x }); // 안 녹는 치즈 위치 저장

			
		}

		// 3. 치즈 녹이기
		for (auto p : toMelt) {
			ary[p.first][p.second] = 0;
		}

		// 4. 1시간 증가 및 치즈 위치 목록 갱신
		time++;
		chzPos = nextChzPos;

	}

	cout << time;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	solve();
}
