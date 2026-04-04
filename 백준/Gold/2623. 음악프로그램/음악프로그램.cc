#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;	// 가수의 수n, 보조PD의 수 m
vector<int> adj[1001];
int in_degree[1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;

		int prev, next;
		cin >> prev;
		for (int j = 1; j < cnt; j++) {
			cin >> next;
			adj[prev].push_back(next);
			in_degree[next]++;

			prev = next;
		}
	}

	/* 위상 정렬*/

	// 1. 큐 생성 및 맨 앞 가수 결정 
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	// 2. 결과 배열 생성
	vector<int> result;

	// 3. 위상정렬 수행
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int next : adj[cur]) {
			in_degree[next]--;
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}

	// 4. 결과 출력
	if (result.size() != n) {
		// 모든 가수를 담을 수 없음, 즉 사이클이 발생한 경우 0 출력
		cout << 0;
	}
	else {
		for (int singer : result) {
			cout << singer << '\n';
		}
	}

}