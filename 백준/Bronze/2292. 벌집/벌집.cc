#include <iostream>
using namespace std;


int main()
{	
	// 1
	// 2 ~ 7
	// 8 ~ 19
	// 20 ~ 37
	
	int n;
	cin >> n;

	int count = 1;
	int max = 1;
	while (true)
	{
		if (max >= n)break;

		max += 6*count;
		count++;
	}

	cout << count;

	return 0;
}