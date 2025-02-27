#include <iostream>
using namespace std;

int main()
{
	//  S , M , L , XL , XXL , XXXL  6가지 / 티셔츠는 같은 사이즈의 T장 묶음 주문
	// 펜은 P자루씩 묶음 주문 or 한 자루씩
	
	int N;
	int ary[6];
	int T, P;

	cin >> N; // 참가자의 수 N
	for (int i = 0; i < 6; i++)cin >> ary[i]; // S M L XL XXL XXXL  
	cin >> T >> P; // 묶음의 수 T , P

	int sum = 0;
	int num = 0;
	for (int i = 0; i < 6; i++)
	{
		if (ary[i] > 0) 
		{
			num = ary[i] / T;
			if (num == 0)sum += 1;
			else if (ary[i] % T == 0)sum += num;
			else 
			{
				sum += num + 1;
			}
		}
	}

	int a, b;

	a = N / P;
	b = N % P;

	cout << sum << endl;
	cout << a << " " << b << endl;




	return 0;
}