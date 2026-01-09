#include<iostream>
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;

	int result = 1;
	while (true) {
		if (a == b)break;
		else if (a > b) {
			result = -1;
			break;
		}

		if (b % 2 == 0)b /= 2;
		else if (b % 10 == 1) b = (b - 1) / 10;
		else {
			cout << -1;
			return 0;
		}
		result++;

	}


	cout << result;

	return 0;

}