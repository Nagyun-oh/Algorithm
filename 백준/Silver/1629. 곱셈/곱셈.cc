#include <iostream>
using namespace std;

long long a, b, c;

long long power(long long b) {

	if (b == 0) return 1;
	if (b == 1) return a % c;

	long long rem = power(b / 2) % c;

	if (b % 2 == 0) return rem* rem%c;
	else return rem* rem%c* a% c;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;

	cout << power(b);

}