#include <iostream>
#include <vector>
using namespace std;

int tree[10001];

// start : 현재 서브트리의 시작 인덱스, end : 끝 인덱스 ( 포함 x )
void postOrder(int start, int end) {

	if (start >= end) return;

	int root = tree[start];
	int split = start + 1;

	// 루트보다 커지는 지점을 찾아서 왼쪽과 오른쪽 서브트리 구분
	while (split < end && tree[split] < root) {
		split++;
	}

	postOrder(start + 1, split); // 왼쪽 서브트리 방문   L
	postOrder(split, end); //오른쪽 서브트리 방문        R
	cout << root << '\n';          //				 	 V

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int idx = 0;
	while (cin >> n) {
		tree[idx++] = n;
	}

	postOrder(0, idx);

	return 0;
}