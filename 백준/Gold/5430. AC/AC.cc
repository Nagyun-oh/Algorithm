#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	string str, input;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		deque<int> dq;
		cin >> str>>n; // RDD		
	
		cin >> input;
		
		string num = "";

		for (char c : input)
		{
			if (isdigit(c))
			{
				num += c;
			}
			else if (!num.empty())
			{
				dq.push_back(stoi(num));
				num = "";
			}
		}
		
		int Reverse_flag = 0;
		int except = 0;
		for (int i = 0; i < str.size(); i++)
		{				
			if (str[i] == 'R')
			{
				if (Reverse_flag == 0) Reverse_flag = 1;
				else Reverse_flag = 0;
			}
			else if (str[i] == 'D')
			{
				if (dq.empty())
				{
					except = 1;
					break;
				}

				if (Reverse_flag)
				{
					dq.pop_back();		
				}
				else
				{
					dq.pop_front();			
				}
			}
			
		}
		
		if (!except) 
		{
			cout << "[";
			while (!dq.empty())
			{
				if (Reverse_flag)
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}

				if (!dq.empty())cout << ",";
				
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
		
	}

	return 0;
}