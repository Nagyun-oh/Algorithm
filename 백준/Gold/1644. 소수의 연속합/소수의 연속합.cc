#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> primes;
bool isPrimes[4000000 + 1];

int main() {
	ios::sync_with_stdio(false);
	std::cout.tie(0); cin.tie(0);
	
	cin >> N;
	/* 1은 소수 합이 불가하므로 예외 처리 */
	if (N == 1) {
		std::cout << 0;
		return 0;
	}

	/* 에라토스테네스의 체*/

	// 1. 일단 다 소수로 설정
	for (int i = 2; i <= N; i++)isPrimes[i] = true;
	for (int i = 2; i * i <= N; i++) {

		// 2. 소수의 배수들 다 지워주기
		if (isPrimes[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrimes[j] = false;
			}
		}
	}
	// 3. 추출한 소수로 배열 생성
	for (int i = 2; i <= N; i++) {
		if (isPrimes[i])primes.push_back(i);
	}

	/* 투 포인터*/
	int start = 0, end = 0, sum = 0, ans = 0;
	while (true) {

		if (sum >= N) {
			if (sum == N)ans++;
			sum -= primes[start++];
		}else if (end == primes.size()){
			break;
		}else{
			sum += primes[end++];
		}
		
	}

	std::cout << ans;

}