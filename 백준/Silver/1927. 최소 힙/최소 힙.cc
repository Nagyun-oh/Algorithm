#include <iostream>
#include <queue>
using namespace std;


void entry();
void solve(int x);

priority_queue<int, vector<int>, greater<int>> pq; // 내림차순 우선순위 큐 == 최소 힙
void entry()
{
	int N,x;
	cin >> N;


	while (N--)
	{
		cin >> x;
		solve(x);
	}

}


// 힙 구현 
// c++ 에서 [min/max] heap == 우선순위 큐
void solve(int x)
{
	if (x == 0)
	{
		if (!pq.empty())
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
		else cout << 0 << '\n';
	}
	else pq.push(x);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	entry();
	

	return 0;
}