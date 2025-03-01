#include <iostream>
#include <string>
using namespace std;

int main()
{	
	int T;
	int k, n;
	
	cin >> T;
	int** result; //2차원 배열
	int* rec = new int[T]; // 결과값 저장할 배열

	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;

		//아파트 만들기
		result = new int* [k+1];

		for (int j = 0; j < k+1; j++) {
			result[j] = new int[n];
		}

		for (int y = 0; y <= k; y++)
		{
			for (int x = 0; x < n; x++)
			{
				result[y][x] = 0;	
			}	
		}

		
		// 아파트 인원수 채우기
		int number = 1;
		for (int y = k; y >= 0; y--)
		{
			for (int x = 0; x < n; x++)
			{
				if (y == k) 
				{
					result[y][x] = number++;
				}
				else
				{
					for (int k = 0; k <= x; k++)
					{
						result[y][x] += result[y + 1][k];
					}
				}

			}
		}
	
		
		rec[i] = result[0][n - 1];
	}

	for (int i = 0; i < T; i++)
	{
		cout << rec[i] << endl;
	}


	
	return 0;
}