#include <iostream>
#include <string>

// 크기 순으로 탐색하기 위해
// 제일 작은 수인 666부터 시작하여 1씩 증가해서 순차적으로
// 666을 포함하는 작은 값들을 기록해가며 나아갈 수 있음

int Find(int N)
{
	int start = 666;
	int index = 0;
	std::string str;
	while (true)
	{
		str = std::to_string(start);
		
		for (int i = 0; i < str.length()-2; i++)
		{
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				index++;
				if (index == N) // N번째 수를 찾으면
				{
					return start; //해당 값 반환
				}
				break;
			}
		}
		start++; // 666부터 시작하여 계속해서 값 증가
	}

}

int main()
{
	int N;
	std::cin >> N;

	int Num = Find(N);

	std::cout << Num;

	return 0;
}