#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;	// 1<= N <= 4,000,000
bool is_prime[4000000 + 1];
vector<int> primes;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	if (N == 1) {
		cout << 0;
		return 0;
	}
	
	// 에라토스테네스의 체 
	
	// 1) 2부터 N까지 모든 숫자 써넣기
	for (int i = 2; i <= N; i++)is_prime[i] = true;	

	// 2) 선택: 아직 지워지지 않은 수 중 가장 작은 수 P를 찾기
	for (int i = 2; i * i <= N; i++) {
		// 3) 제거 : P를 제외한 P의 배수들을 모두 지움.
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;	
		}
	}
	for (int i = 2; i <= N; i++) {
		if (is_prime[i])primes.push_back(i);
	}
	 
	// 투 포인터
	int start = 0, end = 0, sum = 0, ans = 0;
	int size = primes.size();
	while (true) {
		if (sum >= N) {
			if (sum == N) ans++;
			sum -= primes[start++];
		}
		else if (end == size) break;
		else {
			sum += primes[end++];
		}
	}

	cout << ans;
}