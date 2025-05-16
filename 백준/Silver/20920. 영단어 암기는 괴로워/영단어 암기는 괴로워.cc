#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 우선순위
// 1. 자주 나오는 단어일수록 앞에 배치
// 2. 해당 단어의 길이가 길수록 앞에 배치
// 3. 알파벳 사전 순으로 배치
// 길이가 M 이상인 단어들만 사용



int N, M;
string str;
vector <string> v;
map <string, int> m; // key = string, value = 빈도

void init()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str.length() >= M)v.push_back(str);
	}
}

bool cmp(string a, string b)
{
	if (m[a] != m[b])return m[a] > m[b]; // 1. 빈도
	if (a.length() != b.length())return a.length() > b.length(); // 2. 길이
	return a < b; // 3. 사전순

}
void method()
{
	for (int i = 0; i < v.size(); i++)
	{
		m[v[i]]++;
	}

	sort(v.begin(), v.end(), cmp); // 문제조건에 따라서 정렬

	v.erase(unique(v.begin(), v.end()), v.end()); // 중복된 단어 제거 

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}

}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	init();
	method();





	return 0;
}