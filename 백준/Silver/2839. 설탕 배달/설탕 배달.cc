#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	//5로 나눈 나머지가 0,1,2,3,4

	int reminder = n % 5;
	int count = 0;
	

	// 나머지가 0
	if (reminder == 0)
	{
		count = n / 5;
	}
	// 나머지가1
	else if (reminder == 1)
	{
		int x = n - 6;
		if(x>=0)count = x / 5 + 2; //항상 나머지가 6?
	}
	// 나머지가2
	else if (reminder == 2) 
	{
		int x = n - 12;
		if(x>=0)count = x/ 5 + 4;
	}
	// 나머지가3
	else if (reminder == 3)
	{
		count = n / 5+1; 
	}
	// 나머지가 4
	else 
	{
		int x = n - 9;
		if(x>=0)count = x/ 5 + 3;
	}

	if (count == 0)count = -1;

	cout << count;
	

	return 0;
}