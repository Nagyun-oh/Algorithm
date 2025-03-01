#include <iostream>
#include <string>
using namespace std;

int main()
{	
	int a, b;
	cin >> a >> b;

	int smaller = 0;
	if (a < b)smaller = a;
	else smaller = b;

	int div = 0;
	for (int i = 1; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			div = i;
		}
	}

	int mul = 0;
	
	mul = (a * b) / div;
	
	cout << div << '\n';
	cout << mul << '\n';

	return 0;
}