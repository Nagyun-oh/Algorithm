#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ary;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	/* 입력 */
	int x;
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> x;
		ary.push_back(x);
	}

	/*  투 포인터 , 누적 합*/
	int sum = 0, start = 0, end = 0;
	int minLen = 2e9;

	while (start <= end) {

		if (sum >= S) {
			minLen = min(minLen, end - start);
			sum -= ary[start++];
		}
		else if (end == N)break;
		else sum += ary[end++];
	}

	/* 출력 */
	if (minLen != 2e9) cout << minLen;
	else cout << 0;
}