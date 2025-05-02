#include <iostream>
using namespace std;

// 메모이제이션(dp) 방식 사용

int dp[21][21][21] = { 0 };
int w(int a,int b,int c)
{
	if (a <= 0 || b <= 0 || c <= 0)return 1;
	else if (a > 20 || b > 20 || c > 20)return w(20, 20, 20);
	else if (dp[a][b][c] != 0) // 이미 저장된 값일시
	{
		return dp[a][b][c]; 
	}
	else if (a < b && b < c)
	{
		dp[a][b][c] =  w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	return dp[a][b][c];
}


int main()
{
	// 시간 공간 복잡도 최적화
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)break; // -1 -1 -1 입력시 종료
		int result = w(a, b, c); 
		printf("w(%d, %d, %d) = %d\n", a, b, c, result); //출력
	}
	



	return 0;

}