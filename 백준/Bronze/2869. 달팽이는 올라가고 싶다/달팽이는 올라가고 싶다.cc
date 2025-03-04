#include <iostream>

int main()
{	
	int A, B, V;
	std::cin >> A >> B >> V;

	int day = 1;

	day += (V - A) / (A - B);
	
	if ((V - A) % (A - B) != 0)
	{
		day++;
	}

	if (A >= V)
	{
		std::cout << 1;
	}
	else {
		std::cout << day;
	}
	
	return 0;
}