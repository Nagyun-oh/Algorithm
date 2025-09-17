#include <iostream>
#include <string>


using namespace std;

int N;
int idx1, idx2;
void init();
void solve();

void init()
{
	cin >> N;
	string str;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		if (str == "KBS1")idx1 = i;
		else if (str == "KBS2")idx2= i;
	}

}

// 1. i -> i+1
// 2. i -> i-1
// 3. i<-> i+1 , 화살표는 i+1을 가리킴
// 4. i <-> i-1 , 화살표는 i-1을 가리킴
void solve()
{
	int x = idx1 - 1;
	for (int i = 1; i <= x; i++)
	{
		cout << "1";
	}
	
	for (int i = 1; i <= x; i++)
	{
		cout << 4;
	}

	if (idx1 > idx2)idx2 += 1;

	x = idx2 - 1;

	for (int i = 1; i <= x; i++)
	{
		cout << 1;
	}

	for (int i = 1; i <= x - 1; i++)
	{
		cout << 4;
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