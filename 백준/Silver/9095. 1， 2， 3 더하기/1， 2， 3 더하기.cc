#include <iostream>

using namespace std;

void init();
void solve(int n);

int num;
int dp[12];

void init()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> num;
		solve(num);
	}

}

// 정수 n을 1,2,3의 합으로 나타내는 방법의 수 
// 입력받는 1<= n <=11 인 정수
// 순서 존재
// dp문제였네 -> 1. 초기값 설정 -> 2. 점화식 설정
void solve(int n)
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4; 

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cout << dp[n] << '\n'; // 줄바꿈 안했네 

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();


}