#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
int n, m, goal;

vector<pair<int,int>> v[1001];
int dist_to_goal[1001];
int goal_to_dist[1001];
int mx = 0;

void Dijkastra(int start,int* dist) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({ start,0 });

	fill(dist, dist + 1001, INF);
	dist[start] = 0;

	while (!q.empty()) {
		int dx = q.top().first;
		int sum_dist = q.top().second;
		q.pop();

		if (sum_dist > dist[dx])continue;

		for (size_t i = 0; i < v[dx].size(); i++) {
			int nx = v[dx][i].first;
			int ncost = sum_dist + v[dx][i].second;

			if (ncost < dist[nx]) {
				dist[nx] = ncost;
				q.push({ nx,ncost });
			}

		}
	}
	
	int ans = dist_to_goal[goal] + goal_to_dist[start]; // 왕복 시간 계산
	mx = max(mx, ans); // 최대 왕복 시간 구하기

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> goal;
	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
	}

	
	Dijkastra(goal,goal_to_dist); // 도착지 -> 각 학생 으로 가는 거리(시간) 계산

	// 각 학생 -> 도착지로 가는 거리(시간) 계산
	for (int i = 1; i <= n; i++) {
		if (i == goal)continue;
		Dijkastra(i,dist_to_goal); // 각 학생별 x로가는 시간 계산
	}

	cout << mx;

	return 0;
}