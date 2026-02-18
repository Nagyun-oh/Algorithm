#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int ary[101][101];
int visited[101][101];
int cnt;

vector<pair<int, int>> cheezePos;

int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

void input() {
	// N x M
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> ary[i][j];

			if (ary[i][j] == 1) {
				cheezePos.push_back({ i,j });
			}
		}
	}
}

// 1.  외부 공기 = 2 , 내부공기 = 0 구분
void bfs() {

	memset(visited, 0,sizeof(visited));
	queue<pair<int, int>> q;

	// 0,0 은 항상 공기이므로 여기서 시작
	q.push({ 0,0 });
	visited[0][0] = 1;
	ary[0][0] = 2;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + direct[i][0];
			int dx = x + direct[i][1];

			if (dy<1 || dy>n || dx<0 || dx>m)continue;

			if (!visited[dy][dx] && ary[dy][dx] != 1) {
				visited[dy][dx] = 1;
				ary[dy][dx] = 2;
				q.push({ dy,dx });
			}
			
		}
	}

}


void solve() {
	
	
	int time = 0;
	while (!cheezePos.empty()) {
		bfs(); // 외부공기, 내부 공기 구분

		vector<pair<int, int>> nextCheeze;
		vector<pair<int, int>> toMelt;

		// 2. 현재 치즈들 검사
		for (auto p : cheezePos) {
			int y = p.first;
			int x = p.second;
			int airCnt = 0;

			for (int i = 0; i < 4; i++) {
				
				int ny = y + direct[i][0];
				int nx = x + direct[i][1];

				if (ary[ny][nx] == 2)airCnt++;
			}

			if (airCnt >= 2)toMelt.push_back({ y,x }); // 외부공기와 2변이상이면 녹여야하는 치즈
			else nextCheeze.push_back({ y,x });

			//3. 치즈 녹이기
			for (auto p : toMelt) {
				ary[p.first][p.second] = 0;
			}

		}

		cheezePos = nextCheeze; // 남은 치즈 목록 갱신
		time++; // 시간 증가
	}
	
	cout << time;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	solve();
	
}