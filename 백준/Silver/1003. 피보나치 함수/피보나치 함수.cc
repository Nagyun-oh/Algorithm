#include <iostream>

using namespace std;

int fibonacci(int n);
void init();
void solve(int n);

int T; // 테스트 케이스 개수
int count_0; // 0 횟수 기록용
int count_1; // 1 횟수 기록용

int fib[40] = { 0,1 };

// 해결 -> 동적 프로그래밍을 이용한 피보나치 수열 구현
int fibonacci(int n)
{
	if (n == 0 || n == 1)return fib[n];

	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[n];

}

// 입력받기
void init()
{
	cin >> T;
	int n;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "1 0\n";
			continue;
		}

		solve(n);
	}
}

// 메서드
void solve(int n)
{
	fibonacci(n);
	cout << fib[n - 1] << " " << fib[n] << '\n';
}

// 첫 시도 -> 시간초과  
// -> 문제에서 주어진 피보나치 함수가 재귀함수라서 그런듯 -> O(N^2)
// 피보나치 수열을 재귀가 아닌 다른 형태로 바꾸면 될듯.
// - > 메모이제이션 방식 (재귀에서 값을 미리 저장하여 재활용하는 형태)

// -> 0과 1에 대해서도 피보나치 규칙 발생
// N = 0 | 1,0
// N = 1 | 0,1
// N = 2 | 1,1
// N = 3 | 1,2 
// N = 4 | 2,3 
// ....

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

}