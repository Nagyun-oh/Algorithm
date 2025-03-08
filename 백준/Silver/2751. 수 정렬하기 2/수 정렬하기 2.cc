#include <iostream>
#include <algorithm>

bool cmp(long long a, long long b)
{
	return a < b;
}

int main()
{
	int N;
	std::cin >> N;
	long long* ary = new long long[N];

	for (int i = 0; i < N; i++)
	{
		std::cin >> ary[i];
	}

	std::sort(ary, ary + N,cmp);

	for (int i = 0; i < N; i++)
	{
		std::cout << ary[i] << '\n';
	}

	return 0;
}