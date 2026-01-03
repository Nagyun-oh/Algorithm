#include <iostream>
using namespace std;

int N, M;
int arr[9];

void dfs(int num, int depth) {

	if (depth == M) {
		for (int i = 0; i < depth; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = num; i <= N; i++) {
			arr[depth] = i;
			dfs(i, depth + 1);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	dfs(1, 0);



}