#include <iostream>
using namespace std;

int main()
{
	int n, random, v;
	
	cin >> n;

	int* ary = new int[n]; // 1차원 배열 동적 할당

	for (int i = 0; i < n; i++) {
		cin >> random;
		ary[i] = random;
	}
	
	cin >> v;

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (ary[i] == v) {
			count++;
		}
	}
	cout << count << "\n";


	delete[] ary; //메모리 해제

	return 0;
}