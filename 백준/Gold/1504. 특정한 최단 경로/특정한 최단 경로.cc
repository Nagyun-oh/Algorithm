#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 98765432
int N, E;
vector <pair<int,int>> v[801];
int dist[801];

void bfs(int a) {

	memset(dist, INF, sizeof(dist));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,a });
	dist[a] = 0;
	while (!pq.empty()) {
		int distance = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (distance > dist[x])continue;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = distance + v[x][i].second;

			if (dist[nx] > ncost) {
				pq.push({ ncost,nx });
				dist[nx] = ncost;
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c;
	int v1, v2;
	cin >> N >> E; // 1번 정점에서 N번 정점
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c }); // 연결돼 있는 정점b와 간선의 길이 E
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2; // 반드시 거쳐야 하는 서론 다른 정점 v1 v2

	bfs(1);
	int to_v1 = dist[v1];
	int to_v2 = dist[v2];

	bfs(v1);
	int v1_to_v2 = dist[v2];
	int v1_to_N = dist[N];

	bfs(v2);
	int v2_to_N = dist[N];

	int res = 0;

	res = min({ 986765432,to_v1 + v1_to_v2 + v2_to_N }); // v1->v2->N
	res = min({ res,to_v2 + v1_to_v2 + v1_to_N }); // v2->v1->N

	if (res >= INF)cout << -1;
	else cout << res;

}