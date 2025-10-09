#include <iostream>

using namespace std;


int a1, a0;
int c1, c2;
int n0;

void init();
void solve();

int f_n(int n);
int g_n(int c, int n);

void init()
{
	cin >> a1 >> a0;
	cin >> c1 >> c2;
	cin >> n0;
}

void solve()
{

	for (int i = n0; i <= 100; i++)
	{
		int fn = f_n(i);
		int gn1 = g_n(c1, i);
		int gn2 = g_n(c2, i);

		if (fn <gn1 || fn >gn2)
		{
			cout << 0;
			return;
		}
	}

	cout << 1;
}

int f_n(int n)
{
	return a1 * n + a0;
}

int g_n(int c,int n)
{
	return n * c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	init();

	solve();


}