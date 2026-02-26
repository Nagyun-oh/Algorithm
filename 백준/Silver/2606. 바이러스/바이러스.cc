#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 1<= n <=100
int m;
vector<int> v[101];
vector<int> visited;
int ans = 0;

void dfs(int curr) {

	visited[curr] = 1;

	for (auto nx : v[curr]) {

		if (!visited[nx]) {
			ans++;
			dfs(nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int from, to;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	
	visited.assign(101, 0);
	dfs(1);
	cout << ans;

}