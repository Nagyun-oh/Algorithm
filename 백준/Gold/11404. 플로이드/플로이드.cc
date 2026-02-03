#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;
int dist[101][101];  // dist[시작도시][도착도시] = 비용
int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0; // 셀프루프는 거리가 0

	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	// 플로이드 워셜
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // i->j 랑 i->k->j 경로 비교
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

}