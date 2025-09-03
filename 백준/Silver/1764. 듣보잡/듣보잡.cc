#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N, M;
map <string, int> hash_table;
vector<string> No_hear; // 듣도 못한 사람
vector<string> No_See; // 보도 못한 사람

void init()
{
	string str;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		No_hear.push_back(str);
		hash_table[str] = 1;
	}

	for (int j = 0; j < M; j++)
	{
		cin >> str;
		No_See.push_back(str);
		if (hash_table[str] == 1) hash_table[str] = 2;

	}

}

void solve()
{
	vector<string> names;
	int count = 0;

	for (const auto& pair : hash_table)
	{
		if (pair.second == 2)
		{
			names.push_back(pair.first);
			count++;
		}
	}

	cout << count << '\n';
	
	for (const string& name : names)
	{
		cout << name << '\n';
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	init();
	solve();

}