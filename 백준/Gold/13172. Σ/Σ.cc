#include <iostream>
#include <vector>
using namespace std;

int M;
long long N, S;
vector<pair<int, int>> v;

#define X 1000000007

// base^exp (mod X) 구하기
int modPow(long long base, long long exp) {
	long long result = 1; // 항등원
	base %= X;
	
	// 분할 정복
	while (exp > 0) {
		if (exp % 2 == 1) result = (result * base) % X;
		base = (base * base) % X;
		exp /= 2;
	}

	return result;
}


// 페르마의 소정리에 의해 b^x-2 = b^-1 (mod X)
int mod(int base) {
	int inverse = modPow(base, X - 2);
	return inverse;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> N >> S;
		v.push_back({ S,N });
	}
	
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		// 1. Q = S/N (modX) 
		long long s = v[i].first;
		long long n = v[i].second;

		// 2. N^-1 구하기 (모듈러 연산 통해)
		long long inverse_n = mod(n);

		// 3.  Q = S* N^-1 (modX)를 구한다.
		long long Q = (s * inverse_n) % X;

		// 4. 덧셈
		sum += Q;
		sum %= X;
		
	}

	cout << sum;

}