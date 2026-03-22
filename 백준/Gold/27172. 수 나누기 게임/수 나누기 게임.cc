#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;	// 플레이어의 수, 2 <= N <= 100,000
int mx;

int cards[100001];
int score[1000001];
bool isPresent[1000001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cards[i];	
		isPresent[cards[i]] = true;
		if (cards[i] > mx) mx = cards[i];
	}

	for (int i = 1; i <= N; i++) {
		int curr = cards[i];

		for (int mul = curr * 2; mul <= mx; mul += curr) {

			if (isPresent[mul]) {
				if (mul % curr == 0) {
					score[mul] -= 1;
					score[curr] += 1;
				} 
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << score[cards[i]] << " ";
	}

}