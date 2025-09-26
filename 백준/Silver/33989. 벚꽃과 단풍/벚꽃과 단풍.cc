#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string str;
	cin >>n>> str;

	vector<int> prevD(n + 1, 0); 
	for (int i = 0; i < n; i++)prevD[i + 1] = prevD[i] + (str[i] == 'D');

	vector<int>nextB(n + 1, 0);
	for (int i = n - 1; i >= 0; i--)nextB[i] = nextB[i + 1] + (str[i] == 'B');

	int cnt = n;

	for (int i = 0; i <= n; i++)
	{
		int flips = prevD[i] + nextB[i];
		cnt = min(cnt, flips);
	}

	cout << cnt;
}