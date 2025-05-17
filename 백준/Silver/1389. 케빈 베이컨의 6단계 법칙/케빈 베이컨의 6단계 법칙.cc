#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // mem
using namespace std;

int N, M;
vector <vector<int>> v;
vector <int> result;
bool visited[101];
int sum;
int MIN = 99999999;
int min_idx;

void fast();
void init();
int bfs(int start);

// BFS : 그래프나 트리에서 가까운 노드부터 차례로 탐색하는 알고리즘
// 따라서 문제의 논리와 맞음

int main()
{
	fast();
	init();

}

void fast()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

void init()
{
	// ========Input========
	cin >> N >> M;

	// 2차원 배열을 v[0],v[1] = {연결된 정점들} , v[2] = {연결된 정점들} , ....v[N]  = {연결된 정점들} 이런식으로 사용할 수 있게 설정
	v.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int first, second;
		cin >> first >> second;
		// 연결되는 정점들을 설정해줌.
		v[first].push_back(second);
		v[second].push_back(first);
	}
	// =========================

	for (int i = 1; i < v.size(); i++)
	{
		memset(visited, false, sizeof(visited)); // 방문 배열 초기화
		result.push_back(bfs(i));
	}

	for (int i = 0; i < result.size(); i++)
	{
		if (MIN > result[i])min_idx = i;
		MIN = min(MIN, result[i]);
	}

	cout << min_idx + 1;

}

// 최단경로 반환
int bfs(int start)
{
	visited[start] = true;
	sum = 0; // 거리 총합 변수
	queue<pair<int, int>> q; // <정점,이동거리>
	q.push({ start,0 });

	while (!q.empty())
	{
		int point = q.front().first;
		int distance = q.front().second;
		sum += distance;
		q.pop();
		for (int i = 0; i < v[point].size(); i++)
		{
			int next = v[point][i];
			if (!visited[next])
			{
				visited[next] = true;
				q.push({ next,distance + 1 });
			}
		}
	}
	return sum;
}
