#include <iostream>
using namespace std;

int main()
{
	int ary[8];

	for (int i = 0; i < 8; i++)cin >> ary[i];

	int flag = 0; // -1 0 1

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (ary[i] < ary[j])flag = 1; // ascending
			else if (ary[i] > ary[j])flag = -1; //descending
		}
	}

	// mixed 판별
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			if (flag == 1)
			{
				if (ary[i] > ary[j])
				{
					flag = 0;
					break;
				}
			}

			else if (flag == -1)
			{
				if (ary[i] < ary[j])
				{
					flag = 0;
					break;
				}

			}
		}
		if (flag == 0)break;
	}

	if (flag == 1)cout << "ascending\n";
	else if (flag == 0)cout << "mixed\n";
	else if (flag == -1)cout << "descending\n";




	return 0;
}