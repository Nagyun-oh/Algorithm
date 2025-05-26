#include <iostream>
#include <stack>
using namespace std;

int N;
int ary[500001];
int result[500001];

void init()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> ary[i];
	}
	
}

void method()
{
	stack<int> st; 

	for (int i = 1; i <= N; i++)
	{	
		// 첫 루프에서는 수신을 못하는 가장 왼쪽 탑을 다루므로 어차피 result[i] = 0
		// 자신보다 작거나 같은 탑은 제거 (수신 못하는)
		while (!st.empty() && ary[st.top()] <= ary[i])
		{
			st.pop();
		}

		if (st.empty())result[i] = 0;
		else result[i] = st.top();

		st.push(i); // 현재 탑 push

	}

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	method();

	return 0;
}