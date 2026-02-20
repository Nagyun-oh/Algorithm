#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct info {
	int to;
	int dist;
};

int v;
vector<info> graph[100001];
int visited[100001];

int maxNode;
int maxDist;

void dfs(int node, int sumDist) {

	if (visited[node]) return; // 방문했으면 리턴

	visited[node] = true; // 방문 처리

	if (maxDist < sumDist) {
		maxDist = sumDist;
		maxNode = node;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		int nextNode = graph[node][i].to;
		int nextDist = graph[node][i].dist;
		dfs(nextNode, sumDist + nextDist);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int from, to, dist;

	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> from;
		while (true) {

			cin >> to;
			if (to == -1)break;
			cin >> dist;

			// 트리니까 무방향 그래프
			graph[from].push_back({ to,dist });
			graph[to].push_back({ from,dist });
		}
	}


	// 임의의 정점 1에서 가장 먼 정점 구하기
	dfs(1, 0);

	// 다시 탐색할거니까 방문 배열 및 최대 길이 초기화
	memset(visited, 0, sizeof(visited));
	maxDist = 0;

	// 가장 먼 정점에서 출발하여, 가장 긴 탐색길이 구하면, 트리의 지름이 나옴.
	dfs(maxNode, 0);
	
	// 트리의 지름 출력
	cout << maxDist;

}