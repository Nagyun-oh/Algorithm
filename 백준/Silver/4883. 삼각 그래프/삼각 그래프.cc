#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int graph[100001][3], dp[100001][3]; // d[i][j] 는 i행 j열로 이동하는 최소비용
#define NUM 1000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;

	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)break;

		for (int i = 0; i < N; i++)
		{
			cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		}


		// 맨처음에 dp[0][1] 이 선택되게 하기 위한 처리 (맨 위 가운데 정점)
		dp[0][0] = NUM;
		dp[0][2] += dp[0][1];


		for (int i = 1; i < N; i++)
		{
			// 왼쪽 정점 값 + 위쪽에서 받을 수 있는 비용중 최소값
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];  

			// 가운데 정점 값 + 위쪽과 옆에서 받을 수 있는 비용중 최소값 
			dp[i][1] = min(min(dp[i - 1][0], dp[i][0]), min(dp[i - 1][1], dp[i - 1][2])) + dp[i][1];

			// 오른쪽 정점 값 + 왼쪽과 위에서 받을 수 있는 비용중 최소값
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + dp[i][2];
		}
		cout << t++ << ". " << dp[N - 1][1] << '\n';
	}
	return 0;
}