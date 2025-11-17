#include <iostream>
#include <queue>
using namespace std;

int N, M;
char campus[601][601];
int visited[601][601] = { 0 };
pair<int, int> pos; // 도연이 위치
int cnt = 0;

int direct[4][2] = {
	0,1, // 우
	0,-1, // 좌
	1,0,  // 하
	-1,0 // 상
};

void BFS()
{
	queue<pair<int, int>>q;
	q.push(pos);
	visited[pos.first][pos.second] = 1; // 방문여부 체크

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			
			pair<int, int> next = { cur.first + direct[i][0],cur.second + direct[i][1] }; // 이동할 위치

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M)continue; // 범위 벗어나면 스킵

			if (campus[next.first][next.second] == 'X')continue; // X면 스킵

			if (visited[next.first][next.second] == 1)continue;//방문했으면 스킵

			if (campus[next.first][next.second] == 'P') cnt++; // P이면 카운트
			
			
			q.push(next); // 다음 위치 저장
			visited[next.first][next.second] = 1;// 방문여부 체크

		}

	}


}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// N x M 캠퍼스
	cin >> N >> M;
	int start_x, start_y;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				pos.first = i; pos.second = j; // 도연이 위치 저장
			}
		}
	}

	BFS();
	if (cnt > 0)cout << cnt;
	else if (cnt == 0) cout << "TT";




}