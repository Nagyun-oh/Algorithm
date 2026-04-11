#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char mmap[1001][1001];
int visited[1001][1001];
int N, M;
int ans = 0;

int direct[4][2] = {
	-1,0,	// U	0
	1,0,	// D	1
	0,-1,	// L	2
	0,1		// R	3
};

// SAFE-ZONE == 그래프의 구성요소
int dir_index(int y,int x) {

	if (mmap[y][x] == 'U') return 0;
	else if (mmap[y][x] == 'D')	return 1;
	else if (mmap[y][x] == 'L') return 2;
	else if (mmap[y][x] == 'R') return 3;
}

void dfs(int y, int x) {

	visited[y][x] = 1;
	
	int dir = dir_index(y, x);
	int dy = y + direct[dir][0];
	int dx = x + direct[dir][1];
	if (visited[dy][dx] == 0) dfs(dy, dx);
	else if (visited[dy][dx] == 1) ans++;	// 사이클 발견
	
	visited[y][x] = 2;	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	string s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> mmap[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j])dfs(i, j);
		}
	}

	cout << ans;
}