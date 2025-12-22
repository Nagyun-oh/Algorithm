#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int target_y, target_x;
int n, m;
int map[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };

int direct[4][2] = {
	0,-1,
	0,1,
	-1,0,
	1,0
};

// 0 : 갈 수 없는 땅
// 1 : 갈 수 있는 땅
// 2 : 목표 지점 ( 입력에서 2는 단, 한개)
void init() 
{
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x == 2) {
				target_y = i;
				target_x = j;
			}
			map[i][j] = x;
		}
	}

}

void BFS(int start_y, int start_x) {

	queue<pair<int, int>> q;
	q.push({start_y, start_x});
	
	visited[start_y][start_x] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + direct[i][1];
			int dx = x + direct[i][0];

			if (dy >= 0 && dy < n && dx >= 0 && dx < m) {
				
				if (visited[dy][dx] == 0 && map[dy][dx] != 0) {
					visited[dy][dx] = visited[y][x] + 1;
					q.push({ dy, dx });
				}
			}

		}

	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init(); 
	
	BFS(target_y, target_x);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) cout << 0 << " ";
			else cout << visited[i][j] - 1 << " ";
		}
		cout << '\n';
	}


}