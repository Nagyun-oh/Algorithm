#include <iostream>
#include <string>

// N! = N * N-1 * ... 2* 1 => 대칭구조

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	std::cin >> n;

	int count = 0;

	while (n != 0)
	{
		if (n % 125 == 0) // 5^3 이면 0이 3개
		{
			count += 3;
		}
		else if (n % 25 == 0) // 5^2 이면 0이 2개
		{
			count += 2;
		}
		else if (n % 5 == 0) // 5^1 이면 0이 1개
		{
			count += 1;
		}

		n--;
	}

	std::cout << count;

	return 0;
}