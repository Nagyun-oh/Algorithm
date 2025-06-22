#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int>m;
int N, M, n;

void init()
{

	// 가지고 있는 카드 개수 및 카드들 입력
	cin >> N;
	while (N--)
	{
		cin >> n;
		m[n]++; // 해당 key값에 해당하는 값을 map변수에서 증가
	}

	
	// 종류별 카드 수 세기
	cin >> M;
	while (M--)
	{
		cin >> n;
		auto it = m.find(n); // 해당 수 map에서 찾기

		if (it != m.end())
		{
			cout << it->second << " "; // 찾은 수의 개수 출력
		}
		else
		{
			cout << "0 "; // map 에서 존재하지 않으면 0 출력
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	return 0;
}