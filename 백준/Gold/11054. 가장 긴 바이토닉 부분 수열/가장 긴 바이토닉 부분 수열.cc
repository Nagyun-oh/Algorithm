#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ary[1001];
int dp_left[1001];
int dp_right[1001];
int ans;

// 어떤 수 Sk를 기준으로 왼쪽은 오름차순, 오른쪽은 내림차순
void solve() 
{
	for (int i = 1; i <= N; i++) {
		dp_left[i] = 1;
		// 1. 왼쪽에서부터 증가하는 LIS 구하기
		for (int j = 1; j < i;j++) {
			if (ary[j] < ary[i]) {
				dp_left[i] = max(dp_left[i], dp_left[j]+1);
			}
		}		
	}

	for (int i = N; i >= 1; i--) {
		dp_right[i] = 1;
		for (int j = N; j > i; j--) {
			if (ary[j] < ary[i]) {
				dp_right[i] = max(dp_right[i], dp_right[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp_left[i] + dp_right[i] - 1);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ary[i];
	}

	// solve
	solve();

}