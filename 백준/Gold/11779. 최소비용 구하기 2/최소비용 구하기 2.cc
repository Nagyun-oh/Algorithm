#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
int from, to, cost;
int start, endPos;
vector<pair<int, int>> v[1001];
int dist[1001];

int parent[1001];


void Dijkstra(int st) {
	fill(dist, dist + 1001, INF);
	dist[st] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ st,0 });

	while (!q.empty()) {
		int x = q.top().first;
		int sum_dist = q.top().second;
		q.pop();

		if (sum_dist > dist[x]) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = sum_dist + v[x][i].second;

			if (ncost < dist[nx]) {
				dist[nx] = ncost;
				q.push({ nx,ncost });
				parent[nx] = x;
			}

		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
	cin >> start >> endPos;

	Dijkstra(start);

	vector<int> path;

	for (int i = endPos; i != 0; i = parent[i]) {
		path.push_back(i);
		if (i == start) break;
	}
	

	reverse(path.begin(), path.end());

	cout << dist[endPos] << '\n'; // 도착점까지의 비용 출력
	cout << path.size() << '\n'; // 경로 상의 도시의 개수 출력
	for (auto p : path) {
		cout << p << " ";
	}
}