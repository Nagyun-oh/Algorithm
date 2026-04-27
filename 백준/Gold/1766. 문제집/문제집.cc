#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;	// 문제의 수 N , 먼저 푸는 것이 좋은 문제에 대한 정보의 개수 M
vector<int> adj[32001];
int inDegree[32001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		inDegree[B]++;
	}
}

// 위상 정렬 + 우선순위 큐
void solve() {
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int next : adj[cur]) {
			inDegree[next]--;
			if (inDegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	input();
	solve();
}