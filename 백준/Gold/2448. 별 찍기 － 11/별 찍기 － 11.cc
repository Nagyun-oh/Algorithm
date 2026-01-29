#include <iostream>
#include <cstring>
using namespace std;

char board[3073][6146];

// 별찍기 -> 재귀 + 분할정복
// 문제에서는 n이 3일때 기준으로 반복
void draw(int y,int x,int n) {

	if (n == 3) {
		board[y][x] = '*';

		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';

		board[y + 2][x - 2] = '*';
		board[y + 2][x - 1] = '*';
		board[y + 2][x ] = '*';
		board[y + 2][x+1 ] = '*';
		board[y + 2][x+2 ] = '*';

	}
	else {
		draw(y, x, n / 2);
		draw(y + n / 2, x - n / 2, n / 2);
		draw(y + n / 2, x + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	memset(board, ' ',sizeof(board));

	draw(0, n - 1, n); // y좌표, x좌표 , N값

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

}