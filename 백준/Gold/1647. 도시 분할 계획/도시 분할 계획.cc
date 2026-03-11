#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M; // 집의 개수 N, 길의 개수 M
struct info {
	int cost;
	int a;
	int b;
};

vector<info> v;

int parent[100001];

bool cmp(info a, info b) {
	return a.cost < b.cost;
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

	int a, b, c;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		
		v.push_back({ c,a,b });
	}

	// 1. 비용 기준 오름차순으로 정렬
	sort(v.begin(), v.end(), cmp);

	// 2. 부모 배열 초기화
	for(int i=1;i<=N;i++){
		parent[i] = i; // 자기 자신으로 초기화
	}

	int ans = 0, cnt = 0;
	int mx = 0;


	// 3. 크루스칼 알고리즘
	for (int i = 0; i < v.size(); i++) {
		info curEdge = v[i];
		int cost = curEdge.cost;
		int now = curEdge.a;
		int next = curEdge.b;

		if (cnt == N - 1)break; // 최소 모서리 개수 = 정점의 개수 - 1

		// 사이클이면 패스
		if (findParent(now) == findParent(next))continue;

		unionParent(now, next);

		if (mx < cost) {
			mx = cost;
		}

		cnt++;

		ans += cost;
	}


	// ans : 최소한의 비용으로 길을 이어서 하나의 마을로 만들떄의 총 유지비
	// mx : 그 길중 가장 비용이 큰 간선
	// ans - mx : 가장 비용이 큰 간선을 빼면, 비용이 최소인 두 마을이 형성됨.
	cout << ans - mx;

}