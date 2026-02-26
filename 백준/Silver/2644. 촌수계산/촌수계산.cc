#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int a, b;
vector<int> graph[101];
int visited[101];
int final_dist = -1;

void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int dist = q.front().second;
		q.pop();

		visited[x] = true;

		if (x == b) {
			final_dist = dist;
			break;
		}

		for (auto nx : graph[x]) {
			if (!visited[nx]) {
				q.push({ nx,dist + 1 });
			}
		}
	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int pa, ch;

	cin >> n;
	cin >> a >>b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> pa >> ch;
		graph[pa].push_back(ch);
		graph[ch].push_back(pa);
	}
	
	bfs(a);	
	cout << final_dist;
}