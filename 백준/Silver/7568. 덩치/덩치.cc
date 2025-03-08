#include <iostream>
#include <algorithm>

// (x,y)  x : 몸무게 y : 키

struct inform {	
	int x;
	int y;
	int rank;
};

int cmp(inform a, inform b)
{
	return (a.x > b.x) && (a.y > b.y);
}

int main()
{
	int N;
	std::cin >> N;

	inform* temp = new inform[N];
	
	for (int i = 0; i < N; i++)
	{
		std::cin >> temp[i].x >> temp[i].y;
	}
	
	for (int i = 0; i < N; i++)
	{
		temp[i].rank = 1;
		for (int j = 0; j < N; j++)
		{
			if (i!=j&&(temp[i].x < temp[j].x) && (temp[i].y < temp[j].y))
			{
				temp[i].rank++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << temp[i].rank << " ";
	}

	return 0;
}