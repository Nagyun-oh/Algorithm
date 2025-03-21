#include <iostream>
#include <stack>
using namespace std;

void method(string str)
{
	int len = str.size();

	stack<char> left;
	stack<char>right;
	
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			left.push(str[i]);
		}
	
		if (str[i] == ')')
		{
			right.push(str[i]);

			if (!left.empty())
			{
				left.pop();
				right.pop();
			}
			else
			{
				break;
			}

		}
	}
	// ( , ) 각각을 보관하는 스택이 비어있지 않으면 매치 되지 않은 것이므로 flag =1 
	flag = (!left.empty()) || (!right.empty());


	if (flag == 1) cout << "NO\n";
	else cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string str;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		method(str);
	}

	return 0;
}