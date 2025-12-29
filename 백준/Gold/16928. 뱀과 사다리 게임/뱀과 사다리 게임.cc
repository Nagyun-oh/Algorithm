#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> map(101, 0);
vector<int> visit(101, 0);

queue<pair<int, int>>q;

// 모든 칸은 최대 하나의 사다리 또는 뱀을 가지고 있으며, 동시에 두 가지를 가지는 경우는 없음
// 항상 100번칸에 도착할 수 있는 입력만 주어진다.
// 100번 칸에 도착하기 위해 주사위를 "최소" 몇번 굴려야 하는지 구하라. 

void bfs(int start,int c) {
	
	q.push({ start,c });
	while (!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int dpos = pos + i;
			if (dpos == 100) {
				cout << cnt + 1;
				return;
			}
			else if (dpos < 100) {
				if (map[dpos] != 0) {
					dpos = map[dpos];
				}
				if (!visit[dpos]) {
					visit[dpos] = 1;
					q.push({ dpos,cnt+1 });
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; // 사다리의 수 , 뱀의 수
	cin >> N >> M;

	// 뱀과 사디리 입력
	int x, y; 
	for (int i = 0; i < N + M; i++) {
		cin >> x >> y;
		map[x] = y;
	}

	 // bfs가 level단위로 탐색하여, 최소 주사위 횟수를 구하는 것을 보장하려면
	 // cnt는 탐색 방향별로 따로 저장해야함
	 int count = 0; 
	 bfs(1,count);
	 
	
	return 0;
}