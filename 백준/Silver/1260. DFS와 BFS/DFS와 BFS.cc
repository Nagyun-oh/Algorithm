#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, V;  // 정점의 개수 N , 간선의 개수 M, 탐색을 시작할 정점의 번호 V
vector<int> v[10001];
bool visit[1001];

vector<int> dfs;
vector<int>bfs;

void init();
void DFS(int start);
void BFS(int start);

void init()
{
	cin >> N >> M >> V;
	int a, b;
	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b;
		v[a].push_back(b); // 양방향 구현
		v[b].push_back(a); // 양방형 구현
	}

	// 낮은 숫자부터 탐색 (어차피 양방향이라 다 연결되있음)
	for (int i = 1; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}



}

// DFS  -> 재귀로 구현
void DFS(int start)
{
	visit[start] = true; //  방문처리
	dfs.push_back(start); // dfs 경로 저장

	for (int i = 0; i < v[start].size(); i++)
	{
		if (!visit[v[start][i]])
		{
			DFS(v[start][i]);
		}
	}


}

// BFS -> 큐로 규현
void BFS(int start)
{
	queue<int>q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		bfs.push_back(x);

		for (int i = 0; i < v[x].size(); i++)
		{
			if (!visit[v[x][i]])
			{
				q.push(v[x][i]);
				visit[v[x][i]] = true;
			}
		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	DFS(V);

	memset(visit, false, sizeof(visit));

	BFS(V);

	for (int i = 0; i < dfs.size(); i++)
	{
		cout << dfs[i] << " ";
	}
	cout << '\n';

	for (int i = 0; i < bfs.size(); i++)
	{
		cout << bfs[i] << " ";
	}

}