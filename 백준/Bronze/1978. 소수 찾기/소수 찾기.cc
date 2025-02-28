#include <iostream>
using namespace std;


int main()
{	
	int N;
	cin >> N;
	int* ary = new int[N];

	
	for (int i = 0; i < N; i++)cin >> ary[i];

	
	int count = 0;
	int Count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < ary[i]; j++)
		{
			if (ary[i] % j == 0)count++;
		}
		if (count == 1)Count++;

		count = 0;
	}
	
	cout << Count;

	return 0;
}