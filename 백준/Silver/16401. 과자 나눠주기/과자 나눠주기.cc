#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fast ios::sync_with_stdio(),cin.tie(0),cout.tie(0);

int M, N;
vector<int> ary;

void init()
{
	cin >> M >> N; //  입력 : 조카 수 ,과자 수
 	
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		ary.push_back(n);
	}

}

// 이분탐색
void method()
{
	sort(ary.begin(),ary.end()); // 정렬

	int low = 1; // 문제에서 과자의 길이는 최소 1이라고 주어짐
	int high = ary[N - 1]; // 가장 긴 길이

	int rec= 0 ;// 결과값 저장 변수

	// 이분 탐색 
	while (low <= high)
	{
		int mid = (low + high) / 2; // 중앙 값

		int count = 0; //  조카수

		for (int i = 0; i < N; i++)
		{
			count += ary[i] / mid; // 현재 시도하려는 과자 길이 mid 일때 총 몇명에게 줄 수 있는지 계산
		}

		if (count < M)high = mid - 1;  // 줄 수 있는 조카수가 부족하면 길이를 줄인다.
		else 
		{
			// 충분 하면 결과값 저장 및 더 큰 길이 탐색
			rec = mid;
			low = mid + 1;
		}

	}
	cout << rec;

}

int main()
{
	fast;
	init();
	method();

	return 0;
}