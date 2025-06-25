#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include  <deque>

using namespace std;

int n;
vector<int> vec; // 처음에 정렬하기 위한 vector 배열


// 값 입력 및 세팅
void init()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end());

	
}

// 알고리즘

void method()
{
	double sum = 0;
	double total = 0;
	if (n == 0)
	{
		cout << 0;
		return;
	}
	

	// 절사평균 앞 , 뒤 에서의 개수
	int cut = int(round(n * 0.15));
	
	// 절사해서 남은 데이터가 없으면 0출력
	if (cut * 2 >= n)
	{
		cout << 0;
		return;
	}

	for (int i = cut; i < n - cut; i++)
	{
		sum += vec[i];
		total++;
	}
	
	int result = int(sum / total + 0.5);

	cout << result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	method();

}