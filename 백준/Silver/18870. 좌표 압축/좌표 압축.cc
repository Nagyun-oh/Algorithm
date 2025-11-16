#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> vec1;
	vector<int> vec2;

	// 입력
	int N;
	cin >> N; 
	// EX ) 입력 =>{ 2, 4 , -10, 4 ,-9 }
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		vec1.push_back(x); // EX )  { 2, 4, -10, 4, -9 }
		vec2.push_back(x);  // EX )  { 2, 4, -10, 4, -9 }
	}

	sort(vec2.begin(), vec2.end()); // EX )  -10, -9, 2, 4, 4

	vec2.erase(unique(vec2.begin(), vec2.end()),vec2.end());  // EX)  -10 ,-9 , 2, 4
	
	for (int i = 0; i < N; i++)
	{
		// lower_bound(시작위치,끝위치,찾으려는값) : 찾으려는 값보다 크거나 같은 위치 반환
		cout << lower_bound(vec2.begin(), vec2.end(), vec1[i]) - vec2.begin() << " "; // 2 3 0 3 1
	}


}