#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;	// 전체 용액의 수 3<=N<=5000
long long arr[5001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr+1, arr + N+1);
	long long mn = 1e18;

	long long ans[3] = { 0, };

	for (int i = 1; i <= N - 2; i++) {
		int start = i + 1;
		int end = N;
		while (start < end) {
			long long v = arr[i] + arr[start] + arr[end];
			if (abs(v) < mn) {
				mn = abs(v);
				ans[0] = arr[i];
				ans[1] = arr[start];
				ans[2] = arr[end];	
			}
			if (v < 0) start++;
			else end--;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];

}