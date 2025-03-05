#include <iostream>
#include <string>

// 1. 3의배수 ^ 5의 배수 -> 15로 나눈 나머지가 0
// 2. 3의 배수 ^ 5의 배수가 아닐 때 -> 3으로 나눈 나머지가 0 이고 5로 나눈 나머지가 0이 아님
// 3. 3의 배수가 아님 ^ 5의 배수   -> 3으로 나눈 나머지가 0이 아니고 , 5로 나눈 나머지가 0
// 4 . 3의 배수도 아니고 ^ 5의 배수도 아님 -> 3또는 5로 나눈 나머지가 0이아님

int main()
{	
	std::string str[3];

	for (int i = 0; i < 3; i++)
	{
		std::cin >> str[i];
	}

	std::string num;

	int number[3] = { 0 };
	int pos = 0;

	for (int i = 0; i < 3; i++)
	{
		if (str[i] == "FizzBuzz")
		{
			number[i] = 1;
		}
		else if (str[i] == "Fizz")
		{
			number[i] = 2;
		}
		else if (str[i] == "Buzz")
		{
			number[i] = 3;
		}
		else 
		{
			number[i] = 4;
			num = str[i];
			pos = i;
		}
	}

	int Number = std::stoi(num);
	
	int FindNum = Number + 3 - pos;
	
	if (FindNum % 15 == 0)
	{
		std::cout << "FizzBuzz";
	}
	else if (FindNum %3==0&&FindNum%5!=0)
	{
		std::cout << "Fizz";
	}
	else if (FindNum % 3!=0 && FindNum % 5 == 0)
	{
		std::cout << "Buzz";
	}
	else 
	{
		std::cout << FindNum;
	}
	return 0;
}