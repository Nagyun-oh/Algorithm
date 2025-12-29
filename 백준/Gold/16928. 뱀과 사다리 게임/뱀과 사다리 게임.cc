#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> map(101, 0);
vector<int> visit(101, 0);

void bfs(int x,int c) {
	queue<pair<int,int>>q;
	q.push({ x,c });
	while (!q.empty()) {
		int cur = q.front().first; // 현재 지점
		int cnt = q.front().second; // 현재 횟수
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next == 100) {
				// 도착점인 경우 출력 후 종료
				cout << cnt + 1;
				return;
			}
			else if (next < 100) {
				// 사다리 또는 뱀인경우 위치 갱신
				if (map[next] != 0) { // 이떄 if 를 while로 바꿔써도 상관없다
					next = map[next];  // 어차피 각 지점에는 사다리 또는 뱀만 존재하므로, 사다리를 타고 다시 뱀을 연쇄적으로 타는 경우는 없다.
				}
				if (!visit[next]) {
					visit[next] = 1; // 다음에 방문하면 어차피 최소가 아니므로  방문처리를 한다.
					q.push({ next,cnt + 1 });
				}
			}
		}
	}


}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		map[x] = y;
	}
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		map[u] = v;
	}

	bfs(1, 0);

}