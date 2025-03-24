#include <iostream>
using namespace std;

// 재귀를 통한 최대공약수 구하기
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	else return gcd(b, a % b);
}

// 최소공배수 = a*b/두수의 최대공약수
int lcm(int a, int b)
{
	return a * b / gcd(a, b); 
}

void method(int M,int N,int x,int y)
{
	int num = x;
	int tempY = 0;
	int flag = 0;
	int end = lcm(M, N);

	while (num<=end)
	{	
		tempY = num % N;  // y 

		// 나눈 나머지가 0 이면 주기값인 N을 가리킴
		if (tempY == 0)
		{
			tempY = N;
		}

		//발견시
		if (tempY == y)
		{
			flag = 1;
			break;
		}
	
		num += M; // x,y라 할때 x쪽은 M의 주기를 가짐
	}

	if(flag)cout << num << '\n';
	else cout << -1 << '\n';
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// M,N 보다 <= 까지만 증가 
	int T;
	int M, N, x, y;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;
		method(M,N,x,y);
	}

	return 0;
}