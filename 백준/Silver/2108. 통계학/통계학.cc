#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void fast();
void init();
void method();

vector<int> hashtable(8001);
vector<int> v;
vector<int>temp;
int N;
double sum = 0;



int main()
{
	fast();
	init();
	method();

	return 0;
}

void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

}
void init()
{
	int x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		sum += x;
	}
}

void method()
{
	// 1. 산술 평균
	int value1 = round(sum / N);

	sort(v.begin(), v.end());
	
	// 2. 중앙값
	int index = N / 2;
	int value2 = v[index];

	// 3. 최빈값
	for (int i = 0; i < N; i++)
	{
		int idx = v[i] + 4000;
		hashtable[idx] += 1;
	}
	int max = 0;

	int idx;
	
	for (int i = 0; i < 8001; i++)
	{	
		
		if (hashtable[i] > max)
		{
			temp.clear();
			max = hashtable[i];
			temp.push_back(i);
		}
		else if (hashtable[i] == max)
		{
			temp.push_back(i);
		}
	}

	int value3;
	if (temp.size() == 1)value3 = temp.front()-4000;
	else value3 = temp[1]-4000;
	// 4. 범위

	int value4 = v[N - 1] - v[0];

	cout << value1 << '\n';
	cout << value2 << '\n';
	cout << value3 << '\n';
	cout << value4 << '\n';

}