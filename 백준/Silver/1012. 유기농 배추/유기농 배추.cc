#include <iostream>
#include <algorithm>
using namespace std;

int T, M, N, K; // 테스트케이스 , 가로길이 , 세로길이 , 배추가 심어진 위치의 개수
int ary[50][50] = { 0, };

int direct[4][2] =
{
	0,1,  // 하
	0,-1, // 상
	1,0, //우
	-1,0 // 좌
};

int cnt = 0;

void init();
void dfs(int x,int y);


void init()
{
	cin >> T;
	int x, y;
	while (T--)
	{
		for (int i = 0; i < M; i++)
		{
			fill(ary[i], ary[i] + N, 0);
		}

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			ary[x][y] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (ary[i][j] == 1)
				{
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;
	}

}

// 인접한 곳을 탐색해야하므로 -> BFS or DFS
void dfs(int x,int y)
{
	ary[x][y] = 0;

	// 상하좌우에 대한 BFS (깊이 우선 탐색)
	for (int i = 0; i < 4; i++)
	{	
		int dx = x + direct[i][1]; // 행 
		int dy = y + direct[i][0]; // 열

		if (dy<0 || dy>=N || dx<0 || dx>=M)continue; // 배열 유효 범위 넘을경우 넘기기

		if (ary[dx][dy] == 1)
		{
			dfs(dx, dy);
		}
	}

	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	

}