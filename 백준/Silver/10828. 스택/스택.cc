#include <iostream>
#include <string>

using namespace std;


template <typename T>
class Stack
{
private:
	T arr[10000];
	int last;

public:

	void init()
	{
		last = -1;
	}
	void push(int data)
	{
		arr[++last] = data;
	}
	bool empty()
	{
		return (last < 0);
	}
	int pop()
	{
		if (empty())
		{
			return -1;
		}
		else return arr[last--];
	}

	int size() 
	{
		return last + 1;
	}
	int top() 
	{
		if (empty())return -1;
		else return arr[last];

	}

};

void first()
{
	Stack<int> stack;
	stack.init();
	int N;
	string command;
	cin >> N;
	

	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command == "push")
		{
			int n;
			cin >> n;
			stack.push(n);
		}
		else if (command == "pop")
		{
			cout << stack.pop() << '\n';
		}
		else if (command == "size")
		{
			cout << stack.size() << '\n';

		}
		else if (command == "empty")
		{
			if (stack.empty())
			{
				cout << "1\n";
			}
			else cout << "0\n";
		}
		else if (command == "top")
		{
			cout << stack.top() << '\n';
		}
	}

}

int main()
{
	
	first();



	return 0;
}