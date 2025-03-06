#include <iostream>
#include <string>
#include <algorithm>

int cmp(std::string a, std::string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	else
	{
		return a.length() < b.length();
	}

}

std::string ary[20000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> ary[i];
	}

	sort(ary, ary + N,cmp);

	
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			// 중복되는 문자열 flag 처리
			if (ary[i] == ary[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)continue; // 중복되는 문자열일시 출력 x
		std::cout << ary[i] << '\n';
	}


	
	return 0;
}