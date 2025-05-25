#include <iostream>
#include <queue>
using namespace std;

void init();
void BFS(int start);

int N, K; // 수빈이가 있는 위치 N, 동생이 있는 위치 K
int visit[100001];



void init()
{
	cin >> N >> K;
	BFS(N);
}

//수빈이는 걷거나 순간이동
// 1. 걷는다 -> 1초후에 X-1 또는 X+1로 이동
// 2. 순간이동 -> 1초후에 2*X로 이동
// 3. 그리고 x축상에서만 이동함
// 수빈이가 동생을 찾을 수 있는 최단시간 -> 최단경로
// -> BFS 문제

void BFS(int start)
{
	queue<pair<int, int>> q; // <현재 위치, 시간(거리)>
	q.push(make_pair(start, 0)); // 처음위치 초기화
	visit[start] = 1;

	// 큐에서 하나씩 꺼내서->  걷거나, 순간이동 에 대한 경우 시도
	while (!q.empty())
	{
		int x = q.front().first;
		int count = q.front().second;
		q.pop();

		// 동생 찾으면 출력하고 종료
		if (x == K)
		{
			cout << count;
			break;
		}

		// x+1
		if (x + 1 >= 0 && x + 1 < 100001)
		{
			if (!visit[x + 1])
			{
				visit[x + 1] = true;
				q.push(make_pair(x + 1, count + 1));
			}
		}

		// x-1
		if (x - 1 >= 0 && x - 1 < 100001)
		{
			if (!visit[x - 1])
			{
				visit[x - 1] = true;
				q.push(make_pair(x - 1, count + 1));
			}
		}

		// 2*X
		if (2*x >= 0 &&2*x < 100001)
		{
			if (!visit[2*x])
			{
				visit[2*x] = true;
				q.push(make_pair(2*x, count + 1));
			}
		}

	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();


	return 0;
}