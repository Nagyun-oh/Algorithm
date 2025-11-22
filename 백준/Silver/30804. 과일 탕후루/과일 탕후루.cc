#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> v;
	int N; int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x; v.push_back(x);
	}

	int cnt[10] = { 0, }; // 과일 종류별 개수 세기
	int kind = 0; // 과일 종류 수
	int left = 0; 
	int res = 0;

	for (int right = 0; right < N; right++) {
		int fruit = v[right];

		if (cnt[fruit] == 0)kind++; // 새로운 과일이면 종류수 증가
		cnt[fruit]++; // 과일 종류별 개수 갱신

		// 과일 종류 수가 2개 초과인 경우 과일을 뺴야댐
		while (kind > 2) {
			int idx = v[left];

			cnt[idx]--;
			if (cnt[idx] == 0)kind--;
			left++; //앞에서 뻇으니까 다음 거로 이동
		}

		res = max(res, right - left + 1); // 종류 수는 최대로 유지해야함 ( 단, 2종류 이하)

	}
	cout << res;

}