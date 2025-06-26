#include <iostream>
#include <queue>

using namespace std;


int T, N, M;

void init();
void solve(queue<pair<int, int>>& q, priority_queue<int>& pq);

void init()
{
	
	int index, value;
	cin >> T;

	while(T--)
	{
		queue<pair<int, int>> q;
		priority_queue<int>pq; // 항상 가장 큰 값이 top

		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			index = j;
			cin >> value;
			q.push({ index,value });
			pq.push(value);
		}
		solve(q,pq);
	}

}

void solve(queue<pair<int,int>>&q, priority_queue<int>&pq)
{
	int count = 1;
	while (1)
	{
		int nth = q.front().first;
		int value = q.front().second;

		if (value != pq.top())
		{
			q.pop();
			q.push({ nth,value });
		}
		else
		{
			if (nth == M)break;
			else
			{
				q.pop();
				pq.pop();
				count++;
			}
		}
	}

	cout << count << '\n';

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	
	return 0;
}