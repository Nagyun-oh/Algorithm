#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
vector<int> ary(100000 + 1);

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}

	int start = 0,end = 0, sum = 0;
	int mn = 2e9;
	while (start <= end) {

		if (sum >= S) {
			mn = min(mn, end - start);
			sum -= ary[start++];
		}
		else if (end == N) break;
		else {
			sum += ary[end++];
		}
	}

	if (mn != 2e9)cout << mn;
	else cout << 0;

}