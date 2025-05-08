#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define fast ios::sync_with_stdio(),cout.tie(0),cin.tie(0);

int k;
vector<int> input;
int dfs_ary[6]; // 6개씩 고르니까 크기는 6

void init();
void DFS_method(int start,int depth);

void init()
{
	while (true) 
	{
		cin >> k;
		if (k == 0)return;
		
		int a;
		for (int i = 0; i < k; i++)
		{
			cin >> a;
			
			input.push_back(a);
		}
	
		DFS_method(0,0); // 입력된 테스트케이스에 대해서 수행.
		cout << '\n'; // 각 테스트 케이스 사이에는 빈 줄을 하나 출력
		input.clear(); // 배열 비우기
	}
}

// DFS탐색 (재귀방식)
void DFS_method(int start,int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << dfs_ary[i] << " ";
		}
		cout << '\n';
		return;
	}

	
	for (int i = start; i < k; i++)
	{
		dfs_ary[depth] = input[i];
		DFS_method(i + 1, depth + 1);
	}
}

int main()
{
	fast;
	init();

	return 0;
}