#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int D[1001];	// 입력받는 배열
int dp[1001];	// DP
int inDegree[1001];	// 진입차수
vector<int> adj[1001];	// 인접행렬

// 사이클이 없고, 방향성이 있는 그래프이므로, 위상정렬 알고리즘 사용
void solve() {

	/* 입력 처리*/
	int N, K, W;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		
		adj[i].clear();
		dp[i] = 0;
		inDegree[i] = 0;
	}

	for (int i = 0; i < K; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}
	cin >> W;

	/* 알고리즘 수행 */

	queue<int> q;

	/* 시작점 설정 */
	for (int i = 1; i <= N; i++){
		if (inDegree[i] == 0) {
			q.push(i);
			dp[i] = D[i];
		}
	}

	/* 건물 W 짓는데 걸리는 시간 계산 */
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

	/* 출력 */
	cout << dp[W] << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> T;
	while (T--)solve();


}