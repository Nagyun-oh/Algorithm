#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX
#include <functional> // greater
using namespace std;

int n, m;
vector<pair<int, int>>v[1001];
int visit[1001] = { 0, };

// 각 간선별로 비용이 다르고, 최소 비용의 경로를 찾아야 하므로 다익스트라 알고리즘이겠네.
void solve(int st) {
	fill(visit, visit + n+1, INT_MAX);
		
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;// 오름차순 우선순위 큐
	pq.push({ 0,st }); // <비용,도착 도시>
	visit[st] = 0; // 출발 도시 비용 0

	while (!pq.empty()) {
		int cost = pq.top().first; // 현재 도시까지 비용
		int x = pq.top().second; // 현재 도시
		pq.pop();

		if (cost>visit[x])continue; // 현재 도시까지의 비용이 크면 넘기기

		// x도시와 이어진 도시들 검사
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first; //  다음 도시
			int ncost = v[x][i].second + cost; // 다음 도시까지의 비용

			// 기록되어진 비용보다 지금 비용이 더 작으면
			// 큐에 넣기
			if (ncost < visit[nx]) {
				visit[nx] = ncost;// 다음 도시의 최단비용 거리 갱신
				pq.push({ ncost,nx }); 
			}

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> n >> m;
	v[0].push_back({ 0,0 });
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	int st, dt;
	cin >> st >> dt;

	solve(st);

	cout << visit[dt]; // 도착 지점 비용 출력

}