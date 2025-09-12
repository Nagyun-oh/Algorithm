#include <iostream>

using namespace std;

// dp 문제인가 -> dp 문제맞는듯 -> P(N) 간의 규칙성 발견
// Pn = Pn-2 + Pn-3 (N>=4)
// 맞게 구했는데, 왜 틀린가 했더니 결과값을 저장하는 자료형을
// int 가 아니라 long long으로 했어야했다.
// 왜냐하면 피보나치 수열의 값은 N이 커짐에 따라 빠르게 증가하므로,
// 앞으로는 long long 자료형을 써야겠다.

long long int dp[101] = { 0, };

void solve(int N)
{
	// 초기값 설정
	dp[1] = 1;
	dp[2] = 1;
	
	// 점화식
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	cout << dp[N] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int N; // 1<= N <=100
	while (T--)
	{
		cin >> N;
		solve(N);
	}

	
}