#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E; // 1<=V<=10,000 , 1<=E<=100,000
int a, b, c;
int parent[10000 + 1];

struct info {
	int cost;
	int a;
	int b;
};

vector<info> v;

bool cmp(info q, info w) {
	return q.cost < w.cost;
}

int findParent(int x) {
	if (x == parent[x])return x;
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

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;

		v.push_back({ c,a,b });
	}

	// 1. 간선 비용순으로 오름차순 정렬
	sort(v.begin(), v.end(), cmp); 

	// 2. 부모 배열 초기화
	for (int i = 1; i <= V; i++) {
		parent[i] = i;			// 자기 자신으로 초기화
	}

	int ans = 0, cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].cost;
		int now = v[i].a;
		int next = v[i].b;

		if (cnt == V - 1)break; // 간선의 개수 = 정점의 개수 - 1

		// 사이클 체크 ( 부모 같으면 사이클)
		if (findParent(now) == findParent(next))continue;

		unionParent(now, next);

		ans += cost;
		cnt++;
	}

	cout << ans;
}