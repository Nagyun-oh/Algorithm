#include <iostream>
using namespace std;

int N, M;
int know_true;
int answer = 0;

int parent[51];  // 어느 그룹에 속해 있는지
int arr[51][51]; // 파티 번호, 파티 사람 번호
int arrSize[51]; // 각 파티별 인원 수 저장

//==== 유니온 파인드 코드 부분====

int find_p(int x) {
	if (x != parent[x]) return parent[x] = find_p(parent[x]);
	else return parent[x];
}

void mer(int y, int x) {
	int py = find_p(y);
	int px = find_p(x);
	if (py != px) {
		if (py < px)parent[px] = py;
		else parent[py] = px;
	}
}
//================================


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M; // 사람의 수, 파티의 수
	
	// 우선 자기 자신으로 할당
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	cin >> know_true; // 진실을 아는 사람의 수

	// 진실을 아는 사람은 0 집합으로 분류
	int x1;
	for (int i = 0; i < know_true;i++) {
		cin >> x1;
		parent[x1] = 0; 
	}
	
	int x2;
	int num; int first;
	for (int i = 0; i < M; i++) {
		cin >> num; // 파티에 오는 사람 수
		cin >> first; // 파티에 오는 첫번째 사람
		arr[i][0] = first;
		arrSize[i] = num;

		for (int j = 1; j < num; j++) {
			cin >> x2;
			arr[i][j] = x2;
			mer(first, x2);
		}
		
	}

	// 모든 파티에서 거짓말 한 경우에서 시작
	answer = M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < arrSize[i]; j++) {
			if (find_p(parent[arr[i][j]]) == 0) {
				answer--;
				break;
			}
		}
	}

	cout << answer;

}