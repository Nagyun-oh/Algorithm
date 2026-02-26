#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int F, S, G, U, D;
vector<int> visited;
int res = -1;

void bfs() {

	queue<pair<int, int>> q;
	q.push({ S,0 });
	visited[S] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int ntime = q.front().second;
		q.pop();

		if (x == G) {
			res = ntime;
			break;
		}

		if (x + U <= F) {
			if (!visited[x + U]) {
				visited[x + U] = true;
				q.push({ x + U,ntime + 1 });
			}
		}

		if (x - D >= 1 ) {
			if (!visited[x - D]) {
				visited[x - D] = true;
				q.push({ x - D,ntime + 1 });
			}
		}
		
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	visited.assign(F+1, 0); // 방문 배열 초기화

	bfs();

	if (res != -1)cout << res;
	else cout <<"use the stairs";
}