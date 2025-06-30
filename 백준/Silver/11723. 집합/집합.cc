#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M;
vector<int> v;
vector<int> s;

void init()
{
	string str;
	int x;

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		
		if (str == "add")
		{
			cin >> x;
			auto it = find(s.begin(), s.end(), x);
			
			if(it==s.end())s.push_back(x);// x가 없을 경우 추가
		}
		else if (str == "remove")
		{
			cin >> x;
			s.erase(remove(s.begin(), s.end(), x), s.end());
		}
		else if (str == "check")
		{
			cin >> x;
			auto it = find(s.begin(), s.end(), x);
			if (it != s.end())cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "toggle")
		{
			cin >> x;
			auto it = find(s.begin(), s.end(), x);

			if (it != s.end())
			{
				s.erase(remove(s.begin(), s.end(), x), s.end());
			}
			else
			{
				s.push_back(x);
			}
		}
		else if (str == "all")
		{
			s.clear();
			for (int i = 1; i <= 20; i++)
			{
				s.push_back(i);
			}
		}
		else if (str == "empty")
		{
			s.clear(); // 공집합
		}
		
		
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