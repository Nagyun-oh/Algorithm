#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T,n;
vector<int> adj[100001];
int in_degree[100001];

void solve() {
	queue<int> q;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cnt++;

		for (int next : adj[cur]) {
			in_degree[next]--;
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}

	}

	cout << cnt << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
			in_degree[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			int to;
			cin >> to;
			adj[i].push_back(to);
			in_degree[to]++;
		}

		solve();


	}

}