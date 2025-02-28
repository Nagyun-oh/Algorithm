#include <iostream>
#include <string>
using namespace std;
long long M = 1234567891;


int main()
{	
	int L;
	string str;
	cin >> L >> str;

	int n = str.size();

	int* ary = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		ary[i] = str[i] - 96;
	}

	
	long long hash = 0;
	long long r = 1;
	for (int i = 0; i < n; i++)
	{
		hash = (hash+(ary[i] * r))%M;
		r = (r * 31) % M;
		
	}

	cout << hash;

	return 0;
}