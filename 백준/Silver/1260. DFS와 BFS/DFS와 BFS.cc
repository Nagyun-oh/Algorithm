#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int v;
vector<int> graph[1001];
vector<int> visited;

void dfs(int curr) {

	visited[curr] = 1;

	cout << curr << " ";

	for (auto nx : graph[curr]) {

		if (!visited[nx]) {
			dfs(nx);
		}
	}
}

void bfs(int curr) {

	queue<int> q;
	q.push(curr);
	visited[curr] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (auto nx : graph[x]) {
			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = 1;
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int from, to;

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	visited.assign(1001, 0);
	dfs(v);
	cout << '\n';

	visited.assign(1001, 0);
	bfs(v);
	cout << '\n';

}