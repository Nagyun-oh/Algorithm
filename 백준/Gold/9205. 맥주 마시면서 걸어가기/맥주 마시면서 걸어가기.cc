#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct info {
	int y;
	int x;
	int bears;
};

int t;
int n; // 편의점 개수 (0<= n <=100)
int homeY, homeX;
vector<pair<int,int>> cu;
vector<int> visited;
int goalY, goalX;

void bfs() {

	queue<info> q;
	q.push({ homeY,homeX,20 });

	

	while (!q.empty()) {
		int y1 = q.front().y;
		int x1 = q.front().x;
		int bears = q.front().bears;
		q.pop();

		if (abs(y1 - goalY) + abs(x1 - goalX) <= 1000) {
			cout << "happy\n";
			return;
		}


		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				int y2 = cu[i].first;
				int x2 = cu[i].second;
				int dist = abs(y2 - y1) + abs(x2 - x1);

				if (dist <= 1000) {
					visited[i] = true;
					q.push({ y2,x2,20 });
				}
			}
		}
		
	}

	cout << "sad\n";
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int tempY, tempX;
	
	cin >> t;
	
	while (t--) {

		cin >> n;
		visited.assign(n + 1, 0);
		cu.clear();

		// 상근이 집 입력 
		cin >> homeY >> homeX; 

		// 편의점 좌표 입력
		for (int i = 0; i < n; i++) {
			cin >> tempY >> tempX;
			cu.push_back({ tempY,tempX });
		}
		

		// 페스티벌 좌표 입력
		cin >> goalY >> goalX;

		bfs();
	}

}
