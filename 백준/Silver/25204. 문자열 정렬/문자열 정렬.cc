#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T,n;
vector<string> v;

void init();
void solve();
bool comp(string& s1, string& s2);

void init()
{
	string str;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			v.push_back(str);
		}
	

		solve();
	}
}

bool comp(string& s1, string& s2)
{
	int idx1 = 0, idx2 = 0;
	while (idx1 < s1.length() && idx2 < s2.length())
	{
		if (s1[idx1] == s2[idx2])
		{
			idx1++;
			idx2++;
		}
		else
		{
			if (s1[idx1] == '-')return 0;
			if (s2[idx2] == '-')return 1;
			if (tolower(s1[idx1]) != tolower(s2[idx2]))return tolower(s1[idx1]) < tolower(s2[idx2]);
			return s1[idx1] < s2[idx2];
		}
	}
	return s1 < s2;
}

void solve()
{
	sort(v.begin(), v.end(), comp);

	for (auto& s : v)cout << s << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	
}