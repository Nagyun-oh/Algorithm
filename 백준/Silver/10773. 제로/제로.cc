#include <iostream>
#include <stack>

using namespace std;
int k;
int input[100000];
int sum = 0;
stack<int> ary;

void init();
void method(int a);

// 입력 
// method 함수 호출하여 처리
// 합 구하기
void init()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> input[i];
		method(input[i]);
	}

	while (!ary.empty())
	{
		int remain = ary.top();
		ary.pop();
		sum += remain;
	}

	cout << sum;
}

void method(int a)
{
	//0 아니면 push
	if (a != 0) 
	{
		ary.push(a);
	}
	else // 0 이면 stack에서 제거
	{
		ary.pop();
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	
	return 0;
}
