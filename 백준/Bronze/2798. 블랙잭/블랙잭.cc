#include <iostream>
using namespace std;


int main()
{	
	int N, M;
	cin >> N >> M;


	int* card = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> card[i];
	}

	int sum = 0;
	int max = 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N;j++)
		{
			if (j < N) {
				if (card[i] == card[j])continue;
			}
			for (int k = j + 1; k < N; k++)
			{
				if (card[k] == card[j]&&card[k]==card[i])continue;

				
				sum += card[i] + card[j] + card[k];
			
				if (sum > max&&sum<=M)
				{
					max = sum;
				}

				sum = 0;
			}
		}
	}
	
	cout << max << endl;



	return 0;
}