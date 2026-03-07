#include <iostream>
#include <vector>
using namespace std;

int N, R, Q; // 정점의수 N, 루트의 번호 R, 쿼리의 수 Q
vector<int> v[100001];
int subtrees[100001];
int visited[100001];

int countSubtrees(int x) {

	subtrees[x] = 1;
	visited[x] = true;

	for (auto next : v[x]) {
		if (visited[next]) continue; // 부모 노드로 역행 방지

		subtrees[x] += countSubtrees(next);
	}
	
	return subtrees[x];

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int a, b;
	int root;

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	countSubtrees(R);

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << subtrees[q] << '\n';
	}
	
}