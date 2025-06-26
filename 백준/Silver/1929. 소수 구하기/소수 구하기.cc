#include <iostream>
using namespace std;

#define MAX 1000000

// 에라토스테네스의 체 : 소수가 아닌 수 제거
int main()
{
	int M, N;
	cin >> M >> N;

	int* ary = new int[MAX];
	
	// 전체 소수 할당
	for (int i = 2; i <= N; i++)
	{
		ary[i] = i;
	}

	// 에라토스테네스의 체 
	for (int i = 2; i*i <= N; i++)
	{
		if (ary[i] == 0)
		{
			continue;
		}
		for (int j = i * i; j <= N; j += i)
		{
			ary[j] = 0;
		}
	}

	// 결과 출력
	for (int i = M; i <= N; i++)
	{
		if (ary[i] != 0)
		{
			cout << ary[i] << '\n';
		}
	}

	return 0;
}