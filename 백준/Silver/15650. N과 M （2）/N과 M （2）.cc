#include <iostream>
using namespace std;

int N, M;
int ary[9];

void dfs(int n,int depth) {

	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ary[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = n; i <= N; i++) {
			ary[depth] = i;
			dfs(i + 1, depth + 1);
		}
	}


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	dfs(1, 0);




	return 0;
}

