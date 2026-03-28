#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> adj[32001];
int inDegree[32001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}

	queue<int> q;
	// 1. 진입 차수가 0 인 학생들 먼저 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)q.push(i);
	}

	// 2. 위상 정렬
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int next : adj[cur]) {
			inDegree[next]--;

			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}

	return 0;
}