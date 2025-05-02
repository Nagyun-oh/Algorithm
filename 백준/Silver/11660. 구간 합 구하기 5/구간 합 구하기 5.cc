#include <iostream>
using namespace std;

int N; // 표의 크기
int M; // 합을 구해야 하는 횟수
int dp[1200][1200];
void init(); // 초기화 함수
void method(int x1,int y1, int x2,int y2); // 값 구하는 함수

void init()
{
	cin >> N >> M; // N,M
	int temp;
	// 배열 값 채우기
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp; // 0,0 부터 i,j 까지 영역의 값 구하기
		}
	}

	// (x1,y1) (x2,y2) 입력 및 처리
	for (int i = 0; i < M; i++)
	{
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		method(x1, y1, x2, y2);
	}

}

void method(int x1,int y1,int x2, int y2)
{
	int sum = 0;
	sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]; // (x2y2 영역) - (x1-1,y2 영역) - (x2,y1-1영역) + (뺐을 때 겹쳐진 부분인) x1-1, y-1 영역 더하기
	cout << sum << '\n';
}

int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	init();
	

	return 0;

}