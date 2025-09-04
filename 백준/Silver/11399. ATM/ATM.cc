#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> P;

void init()
{
	cin >> N;

	P.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}

}

void solve()
{
	int sum = 0;

	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++)
	{
		sum += P[i];
		for (int j = 0; j < i; j++)
		{
			sum += P[j];
		}
	}

	cout << sum;
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