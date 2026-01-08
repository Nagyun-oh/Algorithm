#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int visited[9];
int res[9];

// 1 7 9 9
void dfs(int depth) {

	if (depth == M) {
		for (int i = 0; i < depth; i++)cout << res[i] << " ";
		cout << '\n';
		return;
	}
	
	int last= 0;

		for (int i = 0; i < N; i++) {
			if (!visited[i]&&arr[i]!=last) {
				last= arr[i];
				res[depth] = arr[i];
				visited[i] = 1; // 방문처리 o
				dfs(depth + 1);
				visited[i] = 0; // 방문처리 x -> 여기서 다시 0으로 설정해야 ex. 1,7 <-> 7,1이 둘다 구해짐
			}
		}
	


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N); // arr[0] ~ arr[N-1] 까지  오름차순 정렬

	dfs(0);

}