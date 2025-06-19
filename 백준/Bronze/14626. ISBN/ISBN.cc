#include <iostream>
#include <string>
using namespace std;

char input[13];
int sum = 0;
int find_num = 0;

void init()
{
	for (int i = 0; i < 13; i++)
	{
		cin >> input[i];
	}
}

void method()
{
	
	int StarOdd = 0;
	for (int i = 0; i < 13; i++)
	{
		int IsOdd = i % 2;
		
		if (input[i] == '*')
		{
			StarOdd = IsOdd;
		}

		if (input[i] != '*')
		{
			
			int num = input[i] - '0';

			if (IsOdd)num*=3;
			sum += num;
		}
	}
	sum %= 10;
	
	// 홀수자리면 3곱함
	if (StarOdd)
	{
		for (int i = 0; i < 10; i++)
		{
			if ((sum + i * 3) % 10 == 0)
			{
				cout << i;
			}
		}
	}
	else
	{
		sum = 10 - sum;
		cout << sum;
	}
	
	

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	init();

	method();


	return 0;
}
