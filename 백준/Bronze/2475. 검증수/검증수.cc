#include <iostream>
using namespace std;

int main()
{
	int ary[5] = { 0 };
	for (int i = 0; i < 5; i++)cin >> ary[i];

	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		sum += ary[i] * ary[i];
	}

	sum %= 10; // 검증수

	cout << sum;


	return 0;
}