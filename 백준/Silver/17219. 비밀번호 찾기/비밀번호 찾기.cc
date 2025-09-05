#include <iostream>
#include <map>

using namespace std;

void init();
void solve(string link);

int M, N;
map <string, string> m;

void init()
{
	string link, pwd;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> link >> pwd;

		m[link] = pwd;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> link;
		solve(link);
	}

}

void solve(string link)
{
	cout << m[link] << '\n';

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

}