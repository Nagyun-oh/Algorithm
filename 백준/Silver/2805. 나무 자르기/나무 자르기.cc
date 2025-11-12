#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// == initalize ===
	long long N, M;  vector<int> tree; // 문제에서 N과 M값이 매우 크게 주어졌으므로 long long
	cin >> N >> M; // 나무의 수 N , 가져가려는 나무의 길이 M
	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		tree.push_back(x);
	}

	//=== solve===
	sort(tree.begin(), tree.end());

	// 너무 큰 input size => 이분 탐색
	long long low = 0; 
	long long high = tree[N - 1];
	long long max = 0;

	
	while (low <= high)
	{
		long long sum = 0;
		long long cut = (low + high) / 2;

		for (int i = 0; i < N; i++)
		{
			if (tree[i] > cut)sum += tree[i] - cut;
		}

		if (sum >= M)
		{
			max = cut; // 현재 cut 지점을 최대값으로 저장
			low = cut + 1; // 길이가 남으므로, 더 크게 자르기 위해 , low = cut+1
		}
		else
		{
			high = cut- 1; // 길이가 부족하므로, 더 작게 자르기 위해, high = cut-1
		}

	}

	cout << max;
}