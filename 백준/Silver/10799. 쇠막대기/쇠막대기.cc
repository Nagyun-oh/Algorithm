#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 레이저가 1개 -> 2개블럭 , 레이저 2개 -> 3개블럭 
// =>  레이저 n개 -> n+1블럭
// '(' 와 ')' 의 index차이가 1이면 레이저 생성 , 2 이상이면 쇠막대기 생성

stack<char> arr; // ( 를 보관하는 스택변수
stack<int> index;  // ( 의 위치를 기억하는 스택변수

void method(string str)
{
	int len = str.size();	
	int count = 0;
	
	for (int i = 0; i < len; i++)
	{

		if (str[i] == '(')
		{
			arr.push(str[i]);
			index.push(i);
		}
		else if (str[i] == ')')
		{
			int curPos = i;
			int MatchPos = index.top(); //  )와 짝지어지는 '(' 위치
			index.pop();
			int CalPos = curPos-MatchPos;

			if (CalPos == 1) // 위치차이가 1이면 레이저 생성
			{
				arr.pop(); // 레이저와 매치되는 ( 는 뺴야 잘못된 연산을 방지함 
				count += arr.size(); // 레이저 생성되면 지금까지 들어간 (의 개수만큼 막대기 개수증가
			}
			else  if (CalPos > 1)// 1 초과이면 막대기 생성하고, 생성된 막대기 개수 1증가
			{
				count += 1;
				arr.pop();
			}
		}
	}

	cout << count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	method(str);


	return 0;
}