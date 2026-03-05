#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N; // 2<= N <= 100,000 이하 정수
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	int x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	int mn = 2e9;

	int left = 0;
	int right = N - 1;

	int resL = 0, resR = 0;

	while (left<right) {
		int value = v[left] + v[right];

		if (abs(value) < mn) {
			mn = abs(value);
			resL = left;
			resR = right;
		}

		if (value < 0) {
			left += 1;
		}
		if (value >= 0) {
			right -= 1;
		}

	}

	cout << v[resL] << " " <<v[resR];


}