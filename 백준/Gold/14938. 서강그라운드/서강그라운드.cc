#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
int n, m, r; // 지역의 개수 , 수색범위 , 길의 개수
int ary[101];
int dist[101];

int mx = 0;

vector<pair<int, int>> v[101]; // 연결된 지역 , 가중치

void Dijkstra(int start) {
	fill(dist, dist + 101, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,start });
		
	dist[start] = 0;

	while (!q.empty()) {
		int sum_dist = q.top().first;
		int x = q.top().second;
		q.pop();

		if (sum_dist > dist[x])continue;

		for (int i = 0; i < v[x].size(); i++) {
			int ncost = sum_dist + v[x][i].second;
			int nx = v[x][i].first;

			if (ncost < dist[nx]) {
				dist[nx] = ncost;
				q.push({ ncost,nx });
			}
		}
	}
	
	int ans = ary[start];
	for (int i = 1; i <= n; i++) {
		if (i == start)continue;
		if (dist[i] <= m) {
			ans += ary[i];
		}
	}
	mx = max(mx,ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)cin >> ary[i];

	int a, b, c;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c }); 
	}

	// 각 i 에서 출발했을때 최대 아이템 수 갱신
	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
	}

	cout << mx;
}