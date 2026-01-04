#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> list;
int arr[9] = { 0, };
int visited[9] = { 0, };

void dfs(int depth) {

	if (depth == M) {
		for (int i = 0; i < depth; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[depth] = list[i];
				dfs(depth + 1);
				visited[i] = false;
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M; // nCm
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		list.push_back(x);
	}
	sort(list.begin(), list.end());

	dfs(0);

}