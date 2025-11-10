#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 1 <= N <= 100,000
int start, End;
vector<pair<int, int>>list;

void init() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> End;
		list.push_back(make_pair(End, start));
	}
}

void solve()
{
	sort(list.begin(), list.end()); // 종료시간을 기준으로 오름차순 정렬

	int time = list[0].first;
	int count = 1;

	for (int i = 1; i < N; i++)
	{
		if (time <= list[i].second)
		{
			count++;
			time = list[i].first;
		}
	}
	cout << count;
}

// 종료시간이 중요함
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();

	return 0;
}