#include <iostream>
#include <vector>
using namespace std;

int N, M; 
vector<int>graph[1001];
int visited[1001];

void DFS(int start)
{
	visited[start] = 1; 

	// 연결된 요소가 없을 때까지 탐색
	for (int i = 0; i < graph[start].size(); i++)
	{
		int idx = graph[start][i];
		if (!visited[idx])
		{
			DFS(idx);
		}
	}

}

int main()
{
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// Initalize
	int u, v;

	// 무방향 그래프 구성
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// solve
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		// DFS에서는 한번 방문하면, 연결된 요소 전부다 방문하므로, 방문여부 체크
		if (!visited[i]) 
		{
			DFS(i);
			count++;
		}
	}

	cout << count;

	return 0;
}