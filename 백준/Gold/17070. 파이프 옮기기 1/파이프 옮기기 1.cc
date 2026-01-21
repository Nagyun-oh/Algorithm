#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int cnt = 0;
int home[17][17];

enum dir{GARO,SERO,DAEGK};

struct information {
	int y;
	int x;
	int status;
};

bool is_in(int y,int x) {
	if (y<1 || y>n || x<1 || x>n || home[y][x] == 1)return false;
	else return true;
}

void bfs() {
	queue<information>q;
	q.push({ 1,2,GARO }); // 초기상태 정의 (처음에 1,1 과 1,2 차지하므로)

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int status = q.front().status;
		q.pop();

		if (y == n && x == n) {
			cnt++;
			continue;
		}

		// 가로/세로/대각선 별로 상태 정의 및 너비 우선 탐색
		if (status == GARO) {

			//가로 이동
			if (is_in(y, x + 1))q.push({ y,x + 1,GARO });

			//대각선 이동
			if (is_in(y + 1, x) && is_in(y, x + 1) && is_in(y + 1, x + 1))q.push({ y + 1,x + 1,DAEGK });

		}
		else if (status == SERO) {

			// 세로 이동
			if (is_in(y + 1, x))q.push({ y + 1,x,SERO });

			//대각선 이동
			if (is_in(y + 1, x) && is_in(y, x + 1) && is_in(y + 1, x + 1))q.push({ y + 1,x + 1,DAEGK });


		}
		else if (status == DAEGK) {

			//가로 이동
			if (is_in(y, x + 1))q.push({ y,x + 1,GARO });
			// 세로 이동
			if (is_in(y + 1, x))q.push({ y + 1,x,SERO });
			//대각선 이동
			if (is_in(y + 1, x) && is_in(y, x + 1) && is_in(y + 1, x + 1))q.push({ y + 1,x + 1,DAEGK });

		}

	}
	
	cout << cnt;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> home[i][j];
		}
	}

	bfs();
}