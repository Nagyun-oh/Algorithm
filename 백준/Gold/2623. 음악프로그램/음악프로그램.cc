#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;	// 가수의 수 n, 보조PD의 수 m
vector<int> adj[1001];
int in_degree[1001];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt;
		cin >> cnt;
		
		int prev, curr;
		cin >> prev;	// 첫번째 가수 입력
		for (int j = 1; j < cnt; j++) {
			cin >> curr;
			// prev-> curr
			adj[prev].push_back(curr);
			in_degree[curr]++;
			prev = curr;	
		}
	}

	// 1. 위상정렬을 위한 큐 생성 및 초기화
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}

	// 2. 결과값을 담을 벡터
	vector<int> result;

	// 3. 위상 정렬 시작
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
	
	// 4. 결과 판별: 모든 가수가 결과에 포함되엇는지 확인
	if (result.size() != n) {
		// 사이클이 발생하여 모든 가수를 세울 수 없는 경우
		cout << 0 << '\n';
	}
	else {
		//성공적으로 줄을 세운 경우
		for (int singer : result) {
			cout << singer << '\n';
		}
	}
	
	return 0;
}