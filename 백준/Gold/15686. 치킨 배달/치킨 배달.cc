#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;
int city[51][51];
int answer = 1e9;
vector<pair<int, int>> chicken;
vector<pair<int, int>>home;
vector<pair<int, int>> points;

int calc_value() {

	int sum = 0;

	for (int i = 0; i < home.size(); i++) {
		int mn = 1e9;
		for (int j = 0; j < points.size(); j++) {
			int a = abs(home[i].first - points[j].first);
			int b = abs(home[i].second - points[j].second);
			
			mn = min(mn, a+b);
		}
		sum += mn;
	}
	return sum;
}

void dfs(int idx) {

	// 치킨집 m개 골랐으면 최소거리 구하기 
	if (points.size() == m) {
		answer = min(answer, calc_value());
		return;
	}


	// 백트래킹
	for (int i = idx; i < chicken.size(); i++) {
		points.push_back(chicken[i]);
		dfs(i + 1);
		points.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];

			if (city[i][j] == 2)chicken.push_back({ i,j });
			else if (city[i][j] == 1)home.push_back({ i,j });
		}
	}

	dfs(0);

	cout << answer;

	return 0;

}