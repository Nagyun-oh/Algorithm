#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x1,x2;
int n, m;
int know_true;
int num;
int answer = 0;

int parent[51]; // 어느 그룹에 속해있는지
int arr[51][51]; // 파티 번호 , 파티 사람 번호
int arrsize[51]; // 각 파티의 인원 수 저장


// 자신의 그룹이 어디에 속해있는지 return
int find_p(int x) {
	if (x != parent[x]) return parent[x] = find_p(parent[x]);
	else return parent[x];
}

// x와 y를 같은 그룹으로 만들기
void mer(int x, int y) {
	int px = find_p(x);
	int py = find_p(y);
	if (px != py) {
		if (px < py)parent[py] = parent[px];
		else parent[px] = parent[py];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i; // 각자 자신의 그룹으로 먼저 분류
	}

	// 진실을 아는 사람은 0 집합으로 분류
	cin >> know_true;
	for (int i = 0; i < know_true; i++) {
		cin >> x1; 
		parent[x1] = 0;
	}

	int first;
	for (int i = 0; i < m; i++) {
		cin >> num; // 파티에 오는 사람 수
		cin >> first; // 파티에 오는 첫번째 사람
		arrsize[i] = num;
		arr[i][0] = first; 
		// 첫번째 사람만 올 경우 혼자 오는 것이라,
		// 다른 사람과 그룹을 합치지 않아도 돼서 따로 분류
		
		for (int j = 1; j < num; j++) {
			cin >> x2;
			arr[i][j] = x2; //파티에 오는 사람 번호 저장
			mer(first,x2);
			
		}
		
	}

	int answer = m; // 전부 거짓말을 할 경우부터 시작

	// 각 파티마다 진실을 아는 사람이 한명이라도 있으면 거짓말 불가하므로 빼기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < arrsize[i]; j++) {
			if (find_p(parent[arr[i][j]]) == 0) {
				answer--;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}