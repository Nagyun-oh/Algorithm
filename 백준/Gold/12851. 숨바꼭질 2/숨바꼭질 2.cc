#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int visited[100001];
int fastTime = -1;
int cnt;

void bfs(int start) {
	bool flag = false; // 가장 빠른 시간 찾기위한 flag 설정

	visited[start] = 1;
	queue<pair<int,int>> q;
	q.push({ start,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int second = q.front().second;
		q.pop();
		visited[x] = second;

		if (fastTime != -1 && second > fastTime) break;

		if (x == K) {
			if (fastTime == -1) {
				fastTime = second;
				cnt = 1;
			}
			else {
				cnt++;
			}
		}

		int move[3] = { x - 1,x + 1,2 * x };

		for (int next : move) {
			if (next >= 0 && next <= 100000) {
				if (visited[next] == 0 || visited[next] == second + 1) {
					visited[next] = second + 1;
					q.push({ next,second + 1 });
				}
			}
		}

	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	bfs(N);

	cout << fastTime << '\n' << cnt;

}