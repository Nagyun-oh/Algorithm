#include <iostream>
using namespace std;

long long N, B;
long long matrix[6][6];
long long ans[6][6];

void multiMatrix(long long matrix1[6][6], long long matrix2[6][6]) {
	long long tmp[6][6];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			long long sum = 0;

			for (int i = 0; i < N; i++) {
				sum += matrix1[y][i] * matrix2[i][x];
			}
			tmp[y][x] = sum % 1000;
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			matrix1[y][x] = tmp[y][x];
		}
	}

}

void init() {
	cin >> N >> B;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
		ans[y][y] = 1; // 단위 행렬 입력 A * I = A
	}
}

void solve() {
	while (B > 0) {
		if (B % 2 == 1)multiMatrix(ans, matrix);  // A^2 * A

		multiMatrix(matrix, matrix); // A^2
		B /= 2;
	}
}

void printMatrix() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << ans[y][x] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	init();
	solve();
	printMatrix();
	
}