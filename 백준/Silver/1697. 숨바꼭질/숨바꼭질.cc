#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int visited[100001];

void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visited[start] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		if (x == k) {
			cout << t;
			break;
		}

		int moving[3] = { x - 1,x + 1,2 * x };

		for (auto next : moving) {
			if (next >= 0 && next <= 100000) {
				if (!visited[next] ) {
					visited[next] = true;
					q.push({ next,t + 1 });
				}
			}
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> k;

	bfs(n);

}