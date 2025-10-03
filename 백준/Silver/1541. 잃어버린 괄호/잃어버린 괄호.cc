#include <iostream>
#include <vector>
#include <string>
using namespace std;


void init();
void solve();

string str; 


void init()
{
	cin >> str;
}

 //입력은 '0' ~ '9' / '+' / '-' 로만 들어옴.
 //가장 처음과 마지막 문자는 숫자이다.
 //숫자는 최대 5자리
 //입력으로 주어지는 식의 길이는 50보다 작거나 같다.


// 우선 문자열에 대하여, 숫자 연산자를 모두 분리해야함
// 다음으로는 식의값이 최소가 되는 괄호의 위치를 찾는 알고리즘 작성
// 연산자가 + 또는 - 니까 '-' 가 활성화 됐을 때, 오는 수 들을 전부 빼주면 값이 최소가 됨.
void solve()
{
	string num = "";
	bool isMinus = false;
	int result = 0;
	
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || i == str.size())
		{
			if (isMinus)
			{
				result -= stoi(num);
				num = ""; // 계산한 피연산자는 버리기
			}
			else
			{
				result += stoi(num);
				num = "";
			}
		}
		else
		{
			num += str[i];
		}

		if (str[i] == '-')
		{
			isMinus = true;
		}
	}


	cout << result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	solve();

	return 0;
}