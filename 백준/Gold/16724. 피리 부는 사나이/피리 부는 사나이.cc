#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char mmap[1001][1001];
int parent[1000*1000+1];
int ans = 0;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

bool unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[b] = a;
		return true;
	}else return false;
}

int get_idx(int y, int x) {
	return y * M + x;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> mmap[i];
	}

	for (int i = 0; i < N * M; i++)parent[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int curr = get_idx(i, j);
			int dy = i; int dx = j;

			if (mmap[i][j] == 'U') dy--;
			else if (mmap[i][j] == 'D')dy++;
			else if (mmap[i][j] == 'L')dx--;
			else if (mmap[i][j] == 'R')dx++;

			int next_idx = get_idx(dy, dx);
			// 사이클 발생
			if (unionParent(curr, next_idx) == false) {
				ans++;
			}
		}
	}

	cout << ans;
}