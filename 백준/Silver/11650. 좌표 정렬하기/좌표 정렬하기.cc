#include <iostream>
#include <algorithm>
using namespace std;

struct pos
{
public:	
	int x;
	int y;
	
	void printInfo()
	{
		cout << x << " " << y << '\n';
	}

};

int cmp(pos a, pos b)
{
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y;
}

int main()
{
	int N;	
	cin >> N;
	
	pos* ary = new pos[N];

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i].x >> ary[i].y;
	}

	sort(ary, ary + N, cmp);

	for (int i = 0; i < N; i++)
	{
		ary[i].printInfo();
	}


	return 0;
}