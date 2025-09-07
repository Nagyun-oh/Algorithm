#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init();
void solve(int n);

int N;
vector<int> ary;
int dp[300];

void init()
{
	
	cin >> N;

	ary.resize(N);
	

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}

	solve(N);
}

// 다음 밟을 계단이 +1 or +2 니까 둘중에 최대값을 가지는 계단을 선택하면 되잖아.
// -> 경우는 2가지
// 내가 밟으려는 계단이 n번째 계단이면, n-1번째 계단을 밟는 경우 & n-3번째 계단
// n-2번째 계단 밟고 n번째 계단 밟기
// 경우의 수를 나눠서 푸는 거구나
void solve(int N)
{
	// 초기 값 설정
	dp[0] = ary[0];
	dp[1] = ary[0] + ary[1];
	dp[2] = max(ary[0] + ary[2], ary[1] + ary[2]);

	// 점화식
	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i - 3] + ary[i - 1] + ary[i], dp[i - 2] + ary[i]);
	}
		
	cout << dp[N-1];
}


// 1. 계단 -> 1계단 or 2계단씩
// 2. 연속된 3개의 계단은 안됨 (시작점은 계단에 포함 x)
// 3. 마지막 도착 계단은 반드시 밟아야함.
// -> 최댓값 찾는거니까 DP문제일거같음.
// Solve : 규칙성 찾고 -> 점화식 도출

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	

}