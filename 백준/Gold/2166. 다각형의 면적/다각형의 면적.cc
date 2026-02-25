#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; // 3 <= N <=10,000

	cin >> N;
	vector<long long> x(N);
	vector<long long> y(N);

	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	// 신발끈 공식
	long long sum1 = 0;
	long long sum2 = 0;

	for (int i = 0; i < N; i++) {
		int next = (i + 1) % N;
		sum1 += x[i] * y[next];
		sum2 += x[next] * y[i];
	}

	double area = abs(sum1 - sum2) / 2.0;

	cout << fixed << setprecision(1) << area;
	
}