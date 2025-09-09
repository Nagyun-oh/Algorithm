#include <iostream>
#include <vector>
using namespace std;

void init();
void DFS(int node);

int n1; // 컴퓨터 수
int n2; // 컴퓨터 쌍의 수

vector<vector<int>> v;
vector<bool>visited;
int cnt = 0;

void init()
{
	int x;
	cin >> n1;
	v.resize(n1+1);
	visited.resize(n1 + 1, false);

	cin >> n2;
	int a, b;
	for (int i = 0; i <n2; i++)
	{
		cin >> a >> b;
		// 양방향 연결리스트
		v[a].push_back(b);
		v[b].push_back(a);
	}

}

// DFS
void DFS(int node)
{
	visited[node] = true;
	cnt++;

	for (int neighbor : v[node])
	{
		if (!visited[neighbor])
		{
			DFS(neighbor);
		}

	}
}




// 자료구조 : DFS & 양방향 연결 그래프
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	DFS(1);
	cout << cnt - 1;
}