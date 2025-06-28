#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void init();
void method();

bool valid = true;
int n;
int x;
int cur = 0;
stack <int> s;
vector<char> v;

void init()
{
	s.push(cur++);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		method();
	}
	
	if (!valid)cout << "NO";
	else
	{
		for (auto i : v)
		{
			cout << i << '\n';
		}
	}

}

void method()
{
	while (s.top() < x)
	{
		s.push(cur++);
		v.push_back('+');
	}

	if (s.top() == x)
	{
		s.pop();
		v.push_back('-');
	}
	else
	{
		valid = false;
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