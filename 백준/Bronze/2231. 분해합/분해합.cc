#include <iostream>
using namespace std;


int main()
{	
	int N;
	cin >> N; 

	
	int min = 0;

	for (int i = 1; i < N; i++)
	{
		int tmp = i;
		int sum = i;

		while (tmp != 0)
		{
			sum += tmp % 10; //1의 자리 더하기
			tmp /= 10;
		}
	
		if (sum == N)
		{
			min = i;
			break;
		}

	}

	
	cout << min << endl;


	return 0;
}