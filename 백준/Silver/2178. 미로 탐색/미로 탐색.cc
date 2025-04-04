#include <iostream>
#include <queue>
using namespace std;

int N, M;
int** MIRO;
int** visited;
int dy, dx;

// 입력
void init()
{
	cin >> N >> M;

	MIRO = new int* [N];
	for (int i = 0; i < N; i++)
	{
		MIRO[i] = new int[M];
	}
	visited = new int* [N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 0;
		}
	}

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < M; x++)
		{
			MIRO[y][x] = str[x] - '0';
		}
	}

	
}

// 미로 탐색
void method()
{
	int direct[4][2] =
	{
		0,1, // 오른쪽 이동
		0,-1, // 왼쪽 이동
		1,0, // 아래로 이동
		-1,0 // 위로 이동
	};

	// 미로문제는 BFS 문제이고, BFS를 위해서는 큐를 써야함
	queue <pair<int, int>> q;
	q.push({ 0,0 });

	int count = 1;
	visited[0][0] = 1;
	while (!q.empty())
	{
		dy = q.front().first;
		dx = q.front().second;
		q.pop();

		bool num_1 = false;
		bool visit = false;
		for (int i = 0; i < 4; i++)
		{
			int newY = dy+direct[i][0];
			int newX = dx+direct[i][1]; 

			// range == true => 범위 안에 있는거
			bool range = (newY >= 0 && newY < N) && (newX >= 0 && newX < M);
			
			if (range) {
				num_1 = MIRO[newY][newX];
				visit = visited[newY][newX]; // 방문했으면 true , 안했으면 false
			}

			if (range&&num_1&&!visit)
			{
				count++;

				q.push({ newY,newX });
				visited[newY][newX] = visited[dy][dx] + 1;
			 // 최단거리 탐색을 위해서는 거리의 길이를 기록해야함
			}


		}		

	}


	cout << visited[N-1][M-1];
}

// 메모리 해제
void destroy()
{
	for (int y = 0; y < N; y++)
	{
		delete MIRO[y];
		delete visited[y];
	}
	delete[] MIRO;
	delete[] visited;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	method();

	destroy();
	

	return 0;
}