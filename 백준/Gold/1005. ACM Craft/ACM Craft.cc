#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;	// 테스트케이스의 개수
int D[1001];	// 각 건물당 건설에 걸리는 시간
int inDegree[1001];
int dp[1001];	// 해당 건물이 완료되는 시점의 시간
vector<int> adj[1001];	// 인접 리스트

void solve() {
	int N, K, W;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		inDegree[i] = 0;
		adj[i].clear();
		dp[i] = 0;
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		inDegree[y]++;	// 나중에 지을 건물의 진입 차수 증가
	}
	cin >> W;
	
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			dp[i] = D[i];	// 시작점
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : adj[cur]) {
			dp[next] = max(dp[next], dp[cur] + D[next]);
			inDegree[next]--;

			if (inDegree[next] == 0) {
				q.push(next);
			}
		}
	}

	cout << dp[W] << '\n';
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> T;
	while (T--)solve();
	
	
}