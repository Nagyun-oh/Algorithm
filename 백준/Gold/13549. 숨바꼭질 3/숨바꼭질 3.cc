#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int n, k; 

const int MAX = 100000;
const int INF = 1e9;

void bfs(int a) {

	fill(dist, dist + MAX + 1, INF); // 거리 배열 초기화

	deque<int> dq;
	dist[a] = 0;
	dq.push_back(a); // 시작점

	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();

		//목표 도착 시 종료 가능
		if (x == k) break;

		// 순간이동 (비용 0)
		int dx = x * 2;
		if (dx <= MAX && dist[dx] > dist[x]) {
			dist[dx] = dist[x];
			dq.push_front(dx); // 앞에 넣어서 먼저 처리
		}

		// 걷기 -1 (비용 1)
		dx = x - 1;
		if (dx <= MAX && dist[dx] > dist[x]+1) {
			dist[dx] = dist[x]+1;
			dq.push_back(dx); // 앞에 넣어서 먼저 처리
		}

		// 걷기 +1 (비용 1)
		dx = x + 1;
		if (dx <= MAX && dist[dx] > dist[x] + 1) {
			dist[dx] = dist[x] + 1;
			dq.push_back(dx); // 앞에 넣어서 먼저 처리
		}

	}
	
	cout << dist[k];

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;

	bfs(n);
	return 0;
}