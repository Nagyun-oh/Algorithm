#include <iostream>
#include <algorithm>
using namespace std;

int ary[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int cost[3];
	for (int i = 1; i <= N; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		ary[i][0] = min(ary[i - 1][2], ary[i - 1][1]) + cost[0]; // i번째 집을 빨간색으로 칠하는 경우
		ary[i][1] = min(ary[i - 1][0], ary[i - 1][2]) + cost[1]; // i번째 집을 초록색으로 칠하는 경우
		ary[i][2] = min(ary[i - 1][0], ary[i - 1][1]) + cost[2]; // i번째 집을 파랑색으로 칠하는 경우
	}

	cout << min(ary[N][2], min(ary[N][0], ary[N][1]));


	return 0;
}