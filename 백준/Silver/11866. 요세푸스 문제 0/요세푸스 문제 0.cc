#include <iostream>
#include <queue>
using namespace std;

int N, K;

void init()
{
	cin >> N >> K;
}

// 순열 구조의 문제에서는 큐가 쓰일 수 있다.
void method()
{
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		q.push(i + 1);
	}

	cout << "<";

	while (!q.empty()) 
	{
		// 요세푸스 순열 규칙에 따라서 숫자 돌리기
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front(); // 출력
		q.pop(); // 출력했으니 제거

		if (q.empty())cout << ">"; // 큐가 비어있으면 이제 끝날거임
		else cout << ", "; // 그렇지 않으면 , 출력
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	method();



	return 0;
}

