#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[100];
int visited[100];

void DFS(int start) {

	for (int i = 0; i < graph[start].size(); i++) {
		int idx = graph[start][i];
		if (!visited[idx]) {
			visited[idx] = 1;
			DFS(idx);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; int a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a)graph[i].push_back(j); // a값이 0이 아니면 경로 생성
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited, 0, sizeof(visited)); // 방향 그래프라 A->B 의 경로가 있다고 B->A경로가 있는 것은 아님.
		DFS(i);
		for (int j = 0; j < N; j++) {
			cout << visited[j] << " ";
		}
		cout << '\n';
	}

}