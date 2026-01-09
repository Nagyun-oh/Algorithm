#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int ary[9] = { 0, };
int res[9] = { 0, };

// 수열의 오름차순 조건을 고려해야됨.
void dfs(int x, int depth) {

	if (depth == M) {
		for (int i = 0; i < depth; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}

	int last = 0;

	for (int i = x; i < N; i++) {
		if (last != ary[i]) {
			last = ary[i];
			res[depth] = ary[i];
			dfs(i,depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> ary[i];

	sort(ary, ary + N);

	dfs(0, 0);

}