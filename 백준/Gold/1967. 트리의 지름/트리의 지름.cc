#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int parent, child, cost;
vector<pair<int, int>> tree[10001];
vector<int> visited(10001, 0);
int max_value = 0;
int max_pos = 0;

// 깊이 우선 탐색
void dfs(int x, int val) {
	visited[x] = 1;

	if (max_value<val) {
		max_value = val;
		max_pos = x;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		int nx = tree[x][i].first;
		int ncost = tree[x][i].second;

		if (visited[nx])continue;
		else dfs(nx, val + ncost);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// Input :  입력 및 트리 생성 
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> parent >> child >> cost;
		tree[parent].push_back({ child,cost });
		tree[child].push_back({ parent,cost });
	}
	
	// Solve : 트리의 지름 구하기

	dfs(1, 0); // 먼저 루트에서 가장 먼 노드 찾기
	visited.assign(10001, 0); // 방문 배열 0으로 초기화
	dfs(max_pos, 0);

	// Print : 트리의 지름 출력
	cout << max_value;
}