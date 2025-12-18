#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	//== Input == 
	int N,M; string S;
	cin >> N >> M >> S;

	//== Solve ==
	// (N+1개의 I) && (N개의 O) => Pn
	
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		int k = 0;
		if (S[i] == 'O')continue;

		while (S[i + 1] == 'O' && S[i + 2] == 'I') {
			k++;

			if (k == N) {
				res++;
				k--;
			}

			i += 2;
		}
	}

	cout << res;
	
}