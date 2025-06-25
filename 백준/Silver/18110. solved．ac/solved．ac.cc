#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include  <deque>

using namespace std;

int n;
vector<int> vec; // 처음에 정렬하기 위한 vector 배열
deque<int> dq; // 앞 뒤로 절사평균 내야 되니까 덱 사용

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
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		dq.push_back(vec[i]);
	}
}

// 알고리즘
// *** 컴파일에러 ****
// : n ==0 일때 예외처리 안함, 절사평균은 ceit (올림)
// 예외처리가 ㅈㄴ많네 ㅅㅂ
void method()
{
	if (n == 0)
	{
		cout << 0;
		return;
	}


	// 절사평균 앞 , 뒤 에서의 개수
	int cut = int(round(n * 0.15));

	if (cut * 2 >= n)
	{
		cut = 0; // 절사 불가능할 땐 절사 x
	}

	//개수 만큼 앞 ,뒤에서 없애기
	for (int i = 0; i < cut; i++)
	{
		dq.pop_back();
	}
	for (int i = 0; i < cut; i++)
	{
		dq.pop_front();
	}

	double sum = 0;
	int total = n - cut * 2;

	if (total <= 0)
	{
		cout << 0;
		return;
	}

	// 합 구하기
	while (!dq.empty())
	{
		sum += dq.front();
		dq.pop_front();
	}

	sum = round(sum / total); // 평균 구하고 반올림
	int result = int(sum); // int형으로 변환

	cout << result; //출력

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	method();

}