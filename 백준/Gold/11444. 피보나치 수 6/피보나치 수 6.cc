#include <iostream>
#include <map>
using namespace std;

#define mod  1000000007

map<long long, long long> m;
 
long long fibo(long long x) {

	if (m.count(x)) return m[x];

	long long res;

	if (x % 2 == 0) res = fibo(x / 2) * (fibo(x / 2 + 1) + fibo(x / 2 - 1)) % mod;
	else res = (fibo((x + 1) / 2) * fibo((x + 1) / 2) % mod + fibo((x - 1) / 2) * fibo((x - 1) / 2) % mod) % mod;

	m[x] = res;

	return m[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;

	m[0] = 0; m[1] = 1; m[2] = 1;
	cout << fibo(n);
		
}