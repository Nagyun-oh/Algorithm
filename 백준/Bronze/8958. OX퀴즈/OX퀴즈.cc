#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string* str = new string[n];
	

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];	
	}
	
	int count = 0;
	int sum = 0;
	int* result = new int[n];
	for (int i = 0; i < n; i++)
	{
		int len = str[i].size();
		for (int j = 0; j < len; j++)
		{
			if (str[i][j] == 'O') 
			{
				count++;
				sum += count;
			}
			else if (str[i][j] == 'X')
			{
				count = 0;
				sum += count;
			}
		}
		result[i] = sum;
		sum = 0;
		count = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}