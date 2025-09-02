#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;
string str;
vector<string> list;
vector<string>input;
map<string, int> dict;


void init()
{
	cin >> N >> M;

	list.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
		dict[list[i]] = i; // 문자열 번호 매핑
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		input.push_back(str);

	}


}

void solve()
{
	for (int i = 0; i < M; i++)
	{
		string str = input[i];
		// 문자열이면
		if (str[0]>=65&&str[0]<=90)
		{
			cout << dict[str] + 1 << '\n';
		}
		else
		{
			cout << list[stoi(str) - 1] << '\n';
			
		}
	}

}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();

}