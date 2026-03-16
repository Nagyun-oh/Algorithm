#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;	// 1<= V <= 10,000  1<= E <= 100,000
int A, B, C;

int parent[10001];

int findParent(int x) {

	if (parent[x] == x)return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {

	a = findParent(a);
	b = findParent(b);

	parent[b] = a;
}

struct info {
	int cost;
	int a;
	int b;
};

vector<info>v;

bool cmp(info a, info b) {
	return a.cost < b.cost;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		v.push_back({ C,A,B });
	}

	// 1. 간선 비용기준 오름차순 정렬
	sort(v.begin(), v.end(), cmp);


	// 2. 부모 노드를 우선 자기 자신으로 초기화
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	

	// 3. 크루스칼 알고리즘
	int cnt = 0, ans = 0;
	for (auto x : v) {
		int cost = x.cost;
		int a = x.a;
		int b = x.b;

		// 최소 간선의개수 = 정점의 개수 -1
		if (cnt == V - 1) break; 

		// 사이클 방지
		if (findParent(a) == findParent(b))continue; 

		unionParent(a, b);

		ans += cost;
		cnt++;
	}
	
	cout << ans;

}