#include <iostream>
#include <string>
using namespace std;

#define MAX 100

template <typename T>
class Stack
{
private:
	int top;
	T ary[MAX];
public:
	Stack() 
	{
		top = -1;
	}
	~Stack(){}
	
	int empty() 
	{
		if (top == -1)return 1;
		else return 0;
	}

	int full()
	{
		if (top == MAX - 1)return 1;
		else return 0;
	}

	void push(T data)
	{
		if (full())exit(1);
		else
		{
			top++;
			ary[top] = data;
		}
	}
	T pop()
	{
		if (empty())exit(1);
		else
		{
			T data = ary[top];
			top--;
			return data;
		}
	}

	T Top()
	{
		if (empty())exit(1);
		else return ary[top];
	}

};

int main()
{


	while (true)
	{
		string input = "";
		Stack<char> s;
		int flag = 1;
		getline(cin, input);

		if (input.size() == 1 && input[0] == '.')
		{
			break;
		}

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '[' || input[i] == '(')
			{
				s.push(input[i]);
			}

			if (input[i] == ']')
			{
				if (!s.empty() && s.Top() == '[')
				{
					s.pop();
				}
				else
				{
					flag = 0;
					break;
				}
			}

			if (input[i] == ')')
			{
				
				if (!s.empty() && s.Top() == '(')
				{
					s.pop();
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}

		if (s.empty() && flag)cout << "yes\n";
		else cout << "no\n";

		
		
	}
	

	return 0;
}