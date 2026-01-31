#include <iostream>
using namespace std;

int N;
int col[15];
int ans = 0;

bool check(int level) {
	for (int i = 0; i < level; i++) {
		// 같은 열에 있거나 대각선에 있으면 공격가능
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) return false;
	}
	return true;
}

// 백트래킹
// x 증가를 통해서, 퀸을 두므로 같은 행에는 어차피 못둠.
// 따라서 행,열,대각선 모두 검사 가능
void Nqueen(int x) {
	if (x == N) ans++;
	else {
		for (int i = 0; i < N; i++) {
			col[x] = i; // x행 i열에 퀸 두기
			if (check(x))Nqueen(x + 1); // check가 참이면, x행 i열에 퀸 두고,  다음 행으로 넘기기
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	Nqueen(0);
	
	cout << ans;
}