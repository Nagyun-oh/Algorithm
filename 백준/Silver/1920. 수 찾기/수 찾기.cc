#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ary[100000];

void binarySearch(int x)
{
	int left = 0;
	int mid = 0;
	int right = N - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (ary[mid] == x)
		{
			cout << "1\n";
			return;
		}
		else if (x<ary[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}


	cout << "0\n";
	return;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}
	
	sort(ary, ary + N);

	int x;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		binarySearch(x);
	}

	return 0;
}