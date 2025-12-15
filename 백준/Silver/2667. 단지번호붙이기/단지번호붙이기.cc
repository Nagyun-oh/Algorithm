#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string str;
int total = 0;
int N; // 입력 N값
int map[25][25]; // 단지 matrix
int cnt = 0; // 단지수 체크
bool visited[25][25] = { 0, }; // 방문체크
vector<int> res;

int direct[4][2] = {
	-1,0, // 상
	1,0,  // 하
	0,-1, // 좌
	0,1   // 우
};

void init();
void DFS(int y,int x);

void init()
{
	cin >> N;  // N

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '1')map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	

}

// 행렬상에서 상하좌우 경로탐색이니까 -> BFS(너비우선탐색) or DFS(깊이우선탐색) 
// DFS(재귀방식구현) , BFS(Queue 방식 구현)
void DFS(int y,int x)
{
		
	for (int i = 0; i < 4; i++) {
		int dy = y + direct[i][0];
		int dx = x + direct[i][1];

		if (dy < 0 || dy >= N || dx < 0 || dx >= N)continue; // 경계조건 체크

		// 집 O && 경계조건 O && 이전에 방문하지 않았으면 
		if (map[dy][dx] == 1 && !visited[dy][dx]) {
			visited[dy][dx] = true;
			cnt += 1;
			DFS(dy, dx);
		}
		
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				cnt = 1;
				DFS(i, j);
				res.push_back(cnt);
				total++;
			}
		}
	}

	sort(res.begin(), res.end());

	cout << total << '\n';

	for (const auto& x : res) {
		cout << x << '\n';
	}

}

