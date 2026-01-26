#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 방향 그래프
// 가중치가 10이하의 자연수면, 다익스트르 알고리즘 이겠네

#define INF 98765432

int v, e;
int k;
vector<pair<int, int>> graph[200001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dist[200001];

// 다익스트라
void bfs(int start) {
	fill(dist, dist+200001,INF);
	dist[start] = 0; // 시작점 자신은 0
	q.push({ 0,start });

	while (!q.empty()) {
		int sum_dist = q.top().first;
		int x = q.top().second;
		q.pop();

		if (sum_dist > dist[x])continue;

		for (int i = 0; i < graph[x].size(); i++) {
			int ncost = sum_dist + graph[x][i].second;
			int nx = graph[x][i].first;

			if (ncost < dist[nx]) {
				dist[nx] = ncost;
				q.push({ ncost,nx });
			}

		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e; // 정점에는 1부터 v까지 번호가 매개져있음
	cin >> k; // 시작 정점의 번호

	// 방향그래프 형성
	int u, v1, w;
	for (int i = 0; i < e; i++) {
		cin >> u >> v1 >> w; // u->v , 가중치 w   
		graph[u].push_back({ v1,w }); // (정점,가중치)
	}

	bfs(k); // 시작점 k에서 각 정점으로 가는 최단 거리 구하기

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)cout << "INF\n";
		else cout << dist[i] << "\n";
	}

}