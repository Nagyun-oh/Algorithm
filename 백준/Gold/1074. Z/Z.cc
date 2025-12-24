#include <iostream>
#include <cmath> // pow
#include <vector>
using namespace std;

int N, r, c;
int ans = 0;

// 분할정복
void search(int y,int x, int size) {
	if (r == y && c == x) {//찾으려는 열과 행이 일치하면
		cout << ans;
		return;
	}
	else if (r >= y && r < y + size && c >= x && c < x + size) {
		// 찾으려는 행과열이 4분면 안에 있는 경우 
		search(y, x, size / 2);
		search(y, x + size / 2, size / 2);
		search(y + size / 2, x, size / 2);
		search(y + size / 2, x + size / 2, size / 2);
	}
	else {
		// 없는 경우 정사각형 넓이 더하기
		ans += size * size;
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> r >> c; 
	search(0, 0, pow(2, N));
	

}