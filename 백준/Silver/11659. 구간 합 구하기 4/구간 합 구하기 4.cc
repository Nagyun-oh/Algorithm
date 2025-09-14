#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> ary;
vector<int>sum;
void init();
void solve(int start,int end);

void init()
{
	int temp = 0;
	cin >> N >> M;  // N = 수의 개수 | M = 합을 구해야 하는 횟수


	ary.resize(N + 1);
	sum.resize(N + 1);
	
	for (int i = 1; i <= N; i++)
	{
		cin >> ary[i];
		temp += ary[i];
		sum[i] = temp;
	}

	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		solve(start, end);
	}


}

void solve(int start,int end)
{
	cout << sum[end] - sum[start - 1] << '\n';
}


// 시간초과 발생
// 누적합으로 풀어야될거같은데 -> ㅇㅇ 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

}