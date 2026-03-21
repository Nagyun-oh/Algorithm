#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 11:45

int n, m;
int a, b;
int parent[500001];


int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int cnt = 0;

	cin >> n >> m;

	// 자기 자신으로 부모 초기화
	for (int i = 0; i <= n - 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		// 사이클일시 출력
		if (findParent(a) == findParent(b)) {
			cout << i+1;
			return 0;
		}
		
		unionParent(a, b);
	}

	cout << 0;

}