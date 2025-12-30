#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<pair<char, int>>comm;
map<int, int> cnt;

void solve() {
	priority_queue<int, vector<int>, less<int>>maxheap;
	priority_queue<int, vector<int>, greater<int>>minheap;
	
	for (int i = 0; i < (int)comm.size(); i++) {
		char c = comm[i].first;
		int n = comm[i].second;

		// 삽입
		if (c == 'I') {
			maxheap.push(n);
			minheap.push(n);
			cnt[n]++;
		}
		// 삭제
		else {
			// 최댓값 삭제
			if (n == 1) {
				if (!maxheap.empty()) {
					cnt[maxheap.top()]--;
					maxheap.pop();
				}
			}
			// 최솟값 삭제
			else if (n == -1) {
				if (!minheap.empty()) {
					cnt[minheap.top()]--;
					minheap.pop();
				}
			}
			// 동기화
			while (!maxheap.empty() && cnt[maxheap.top()] == 0)maxheap.pop();
			while (!minheap.empty() && cnt[minheap.top()] == 0)minheap.pop();
		}
	}

	// 동기화 (연산이 다 끝나고도 불일치 하는 테스트 케이스가 있으므로 여기서도 수행)
	while (!maxheap.empty() && cnt[maxheap.top()] == 0)maxheap.pop();
	while (!minheap.empty() && cnt[minheap.top()] == 0)minheap.pop();

	
	if (maxheap.empty() || minheap.empty())cout << "EMPTY\n";
	else cout << maxheap.top() << " " << minheap.top() << '\n';
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, k;
	cin >> T;
	for (int i = 0; i < T; i++) {
		comm.clear();
		cnt.clear();

		cin >> k;

		char c; int n;
		for (int j = 0; j < k; j++) {
			cin >> c >> n;
			comm.push_back({ c,n });
		}
		solve();
		
	}

}