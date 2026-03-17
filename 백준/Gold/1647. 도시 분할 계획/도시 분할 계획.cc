#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 집의개수 N, 길의 개수 M
int A, B, C; // A번 집과 B번 집을 연결하는 길의 유지비가 C

int parent[100000+1];
struct info {
	int cost;
	int a;
	int b;
};

vector<info> v;

bool cmp(info a, info b) {
	return a.cost < b.cost;
}

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

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		v.push_back({ C,A,B});
	}

	// 1. 비용 기준 오름차순 정렬
	sort(v.begin(), v.end(), cmp);

	// 2. 부모 배열 자기 자신으로 초기화
	for (int i = 1; i <= N; i++)parent[i] = i;

	// 3. 크루스칼 알고리즘
	int mx = 0;
	int ans = 0, cnt = 0;
	for (auto x : v) {
		int cost = x.cost;
		int now = x.a;
		int next = x.b;

		if (cnt == N - 1)break;

		// 사이클 방지
		if (findParent(now) == findParent(next))continue;

		unionParent(now, next);

		ans += cost;
		cnt++;

		if (mx < cost)mx = cost;

	}

	cout << ans - mx;

}
