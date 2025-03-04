#include <iostream>

int main()
{	
	// 시간 복잡도 및 공간복잡도 처리
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	int ary[10001] = { 0 };
	int num;
	

	for (int i = 1; i <= N; i++)
	{
		std::cin >> num;

		ary[num]++;

	}

	for (int i = 1; i <10001; i++)
	{
		for (int j = 0; j < ary[i]; j++)
		{
			std::cout << i << '\n';
		}
	}
	

	
	return 0;
}