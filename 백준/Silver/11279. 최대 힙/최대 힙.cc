#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int x;
	int N;
	
	// 최대 힙 => 우선순위큐
	priority_queue<int> pq;

	cin >> N; // 연산의 개수 N 입력
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if(x>0)pq.push(x);  // 자연수이면, 배열에 X값 추가
		else if (x == 0) // x가 0이라면, 배열에서 가장 큰 값을 출력하고, 그 값 배열에서 제거
		{
			if (pq.empty())cout << 0 << '\n'; // 비어있는 경우 0 출력
			else {
				cout << pq.top() << '\n'; // 우선순위 큐에서 가장 큰값 출력됨
				pq.pop(); // 배열에서 제거
			}
		}
	}

	return 0;
}