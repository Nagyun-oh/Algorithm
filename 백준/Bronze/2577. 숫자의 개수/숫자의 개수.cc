#include <iostream>
#include <string>
using namespace std;

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	int res = A * B * C;

	string result = to_string(res);
	int count[10] ={0};

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j <10; j++)
		{
			if (result[i] == j + '0') {
				count[j]++;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		cout << count[i] << endl;
	}

	return 0;
}