#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321
int n, m;
int a, b, c;
vector<pair<int,int>> v[101];
int dist[101];

// 가중치가 100,000보다 작거나 같은 자연수니까 다익스트라
void djikstra(int start) {

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	fill(dist, dist + 101, INF);
	q.push({ 0,start });
	dist[start] = 0;
	while (!q.empty()) {
		int sum_dist = q.top().first;
		int x = q.top().second;
		q.pop();

		if (sum_dist > dist[x]) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int ncost = sum_dist + v[x][i].second;
			int nx = v[x][i].first;
			if (ncost < dist[nx]) {
				dist[nx] = ncost;
				q.push({ ncost,nx });
			}
		}

	}

	for (int i = 1; i <= n; i++) {
		if (i==start|| dist[i]==INF) cout << 0 << " ";
		else cout << dist[i] << " ";
	}

	cout << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; // 시작도시 도착도시 비용
		v[a].push_back({ b,c }); 
	}

	for (int i = 1; i <= n; i++) {
		djikstra(i); // i에서 출발 했을 때
	}


}

