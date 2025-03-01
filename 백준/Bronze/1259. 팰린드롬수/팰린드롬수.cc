#include <iostream>
#include <string>
using namespace std;


int main()
{	
	int input;
	
	while (true)
	{
		cin >> input; // 정수형 값 입력받기
		if (input == 0)break; // 0 이면 종료
		
		// 일차원 배열 크기 구하기
		int count = 0;
		int tmp = input;
		while (tmp != 0)
		{
			tmp/= 10;
			count++;
		}

		//배열 동적할당 및 값 채우기
		int* ary = new int[count];

		for (int i = 0; i < count; i++)
		{
			int n = input % 10;
			input /= 10;

			ary[i] = n;

		}

		// 팰린드롬수인지 아닌지 확인
		int flag = 1;
		for (int i = 0; i < count / 2; i++)
		{
			if (ary[i] != ary[count - i - 1])
			{
				flag = 0;
				break;
			}
		}

		if (flag == 1)cout << "yes\n";
		else cout<<"no\n";


	}
	

	return 0;
}