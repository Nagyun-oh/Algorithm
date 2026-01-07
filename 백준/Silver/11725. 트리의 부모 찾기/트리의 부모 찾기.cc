#include <iostream>
#include <vector>
using namespace std;


vector<int> v[100001];
int visited[100001];
int ary[100001];

void dfs(int x) {
	visited[x] = 1; // 방문처리를 해야 올바른 값 구하기 가능 ( 그래야 중복 방문 안하므로)

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!visited[next]) {
			ary[next] = x;
			dfs(next);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	int N;
	
	// 트리 구현
	// 우선 트리가 무방향 그래프로 연결되므로 양방향 push
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// 트리의 루트가 1이므로 1에서 내려가면서 탐색 시작
	dfs(1);

	//출력
	for (int i = 2; i <= N; i++) {
		cout << ary[i] << '\n';
	}


}