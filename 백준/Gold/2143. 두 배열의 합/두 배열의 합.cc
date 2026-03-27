#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int n, m;
int A[1001];
int B[1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> T;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
	}

	// 결국 T :  
	// A 누적합 + B 누적합 = T 를 만족하는 경우 이므로,
	vector<int> aSum, bSum;

	/* A 누적합 계산 */
	for (int i = 1; i <= n; i++) {
		int sum = A[i];
		aSum.push_back(sum);
		for (int j = i + 1; j <= n; j++) {
			sum += A[j];
			aSum.push_back(sum);
		}
	}

	/* B 누적합 계산 */
	for (int i = 1; i <= m; i++) {
		int sum = B[i];
		bSum.push_back(sum);
		for (int j = i + 1; j <= m; j++) {
			sum += B[j];
			bSum.push_back(sum);
		}
	}

	sort(bSum.begin(), bSum.end()); // 이분탐색을 위한 정렬

	long long ans = 0;
	for (int i = 0; i < aSum.size(); i++) {
		int target = T - aSum[i];

		/* 이분 탐색 */
		int lo = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin(); // target보다 처음으로 크거나 같아지는 경우 인덱스
		int hi = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin(); // target값을 처음으로 초과하는 경우 인덱스

		ans += hi - lo;
	}

	cout << ans;

}