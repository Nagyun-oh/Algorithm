#include <iostream>

using namespace std;

int n; //  1<= n <= 1000
int dp[1001];

void init();
void solve();


// 2xn 타일링
// 2xn 크기의 직사각형을 1x2 , 2x1 타일로 채우는 방법의 수
// 그러면 세로 길이는 고정이고, 가로 길이만 늘어나네
// dp 문제같은데
void solve()
{
	cin >> n;

	int count = 0;

	// 알고리즘  (DP)

	// 초기값 설정
	dp[1] = 1;
	dp[2] = 2;
	
	// 결국 dp[n] 은 i-1 번째 , i-2 번째 직사각형이 각각 2x1을 쓰거나 1x2로 쓰는 경우
	// 로 나누어지므로 점화식은 다음과같다. 
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
		dp[i] = dp[i] % 10007;
	}


	
	cout << dp[n];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

}