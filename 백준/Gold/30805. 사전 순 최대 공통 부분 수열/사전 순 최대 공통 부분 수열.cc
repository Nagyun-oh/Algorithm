#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
typedef pair<int, int> p;

vector<p> A;
vector<p> B;

bool cmp(p a, p b) {

	if (a.first == b.first) return a.second < b.second; // 값이 같을 경우, 인덱스 기준 오름차순
	else return a.first > b.first;  // 값 다르면, 값 기준 내림차순

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x;

	// == Input ==
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		A.push_back({ x,i });
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		B.push_back({ x,i });
	}

	// == solve ==

	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);
	
	vector<int> ans;

	int idxA = 0, idxB = 0, lastIdxA = 0, lastIdxB = 0;
	while (idxA < N && idxB < M) {

		if (A[idxA].first == B[idxB].first) {

			if (lastIdxA > A[idxA].second) idxA++;
			else if (lastIdxB > B[idxB].second) idxB++;
			else {
				lastIdxA = A[idxA].second;
				lastIdxB = B[idxB].second;
				ans.push_back(A[idxA].first);
				idxA++;
				idxB++;
			}
		}
		else if (A[idxA].first > B[idxB].first) idxA++;
		else idxB++;

	}

	cout << ans.size() << '\n';
	for (auto x : ans)cout << x << " ";

}