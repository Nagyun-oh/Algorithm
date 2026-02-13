#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tc;
int n, m, w;
int s, e, t;

struct edge {
	int from;
	int to;
	int cost;
};

bool solve() {
	vector<edge> v;
	cin >> n >> m >> w;

	// 도로의 정보 
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		// 도로는 양방향 그래프
		v.push_back({ s,e,t });
		v.push_back({ e,s,t });
	}

	for (int i = 0; i < w; i++) {
		cin >> s >> e >> t;
		// 웜홀은 단방향 그래프, 줄어드는 시간이니까 가중치는 음수
		v.push_back({ s,e,-t });
	}

	// ==== Bellman-Ford ====
    // 음수 사이클 있으면 true 반환

	vector<int> dist(n + 1, 0); // 0으로 초기화하여, 모든 정점에서 동시에 시작

	for (int i = 1; i <= n; i++) {
		for (const auto& e : v) {
			if (dist[e.to] > dist[e.from] + e.cost) {
				dist[e.to] = dist[e.from] +e.cost;
				if (i == n) return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 도로는 무방향 , 웜홀은 방향
	// 음수사이클이 존재하는지 체크

	cin >> tc;
	
	while (tc--) {
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}

}