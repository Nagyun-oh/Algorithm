#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int cnt = 0;

vector<int> bigger[100];
vector<int> smaller[100];
bool visited[100];

void DFS(vector<int>v[100], int x)
{
	int size = v[x].size();
	for (int i = 0; i < size; i++) {
		int idx = v[x][i];
		if (!visited[idx]) {
			visited[idx] = true;
			cnt++;
			DFS(v, idx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		bigger[a].push_back(b); // b > a
		smaller[b].push_back(a); // b > a
	}

	int res = 0;
	// 각 구슬 (1<= x <=N ) 에 대해서, 큰/작은 구슬 수 >= N+1/2 판명
	for (int x = 1; x <= N; x++)
	{
		memset(visited, false, sizeof(visited));
		cnt = 0;
		DFS(bigger, x);
		if (cnt >= (N + 1) / 2)res++;

		memset(visited, false, sizeof(visited));
		cnt = 0;
		DFS(smaller, x);
		if (cnt >= (N + 1) / 2)res++;
	}

	cout << res;

	return 0;
}