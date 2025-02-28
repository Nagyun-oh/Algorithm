#include <iostream>
#include <string>
using namespace std;

int pow(int number, int ex)
{
	
	if (ex == 0)return 1;
	
	return number * pow(number, ex - 1);
}

int main()
{	


	int L;
	string str;
	cin >> L >> str;

	int n = str.size();

	int* ary = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		ary[i] = str[i] - 97+1;
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int p = pow(31, i);
		sum += ary[i] * p;
	}

	cout << sum;

	return 0;
}