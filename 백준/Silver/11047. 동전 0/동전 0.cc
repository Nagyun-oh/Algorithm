#include <iostream>


using namespace std;

int N, K;
int ary[10];

void init()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}

}

void solve()
{
	int count = 0;
	int res = 0;
	
	for (int i = N - 1; i >= 0; i--)
	{
		int cur_money = ary[i];
		while (res+cur_money <= K)
		{
			res += cur_money;
			count++;
		}
		if (res == K)break;
	}

	cout << count;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	solve();

}