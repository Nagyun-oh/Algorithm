#include <iostream>
#include <algorithm>
using namespace std;

void init();
void solve();

int cable_K[10001];
int N, K;
int sum = 0;
int max_len = 0;

void init()
{	
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> cable_K[i];
		max_len = max(cable_K[i], max_len);
	}
}

// 이분탐색
void solve()
{
	long long left = 1;
	long long right = max_len;
	long long mid = (left + right) / 2;

	while (left <= right)
	{
		int count = 0;

		for (int i = 0; i < K; i++)
		{
			count += cable_K[i] / mid;
		}
		
		// 케이블 수가 N보다 크거나 같으면, mid 크기를 늘려서 N을 줄여야됨.
		if (count >=N)
		{
			left = mid + 1;
		}
		// 케이블 수가 N보다 작으면, mid 크기를 줄여서 N을 늘려야댐
		else if(count<N) 
		{
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}

	cout << mid;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);	
		
	init();

	solve();

	return 0;
}