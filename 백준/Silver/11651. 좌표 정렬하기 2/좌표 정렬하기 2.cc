#include <iostream>
#include <algorithm>
using namespace std;

// 클래스로 좌표 구현
class pos
{
private:
	int x;
	int y;
public:

	pos()
	{
		this->x = 0;
		this->y = 0;
	}
	~pos() {}

	//setter
	void setPos(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	
	void printInfo()
	{
		cout << x << " " << y << '\n';
	}


	int getX() { return x; }
	int getY() { return y; }

};

// sort 비교연산에 넣을 알고리즘
int cmp(pos a, pos b)
{
	if (a.getY() != b.getY())return a.getY() < b.getY();
	else return a.getX() < b.getX();
}

int main()
{
	int N;
	cin >> N;

	pos* ary = new pos[N];

	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		ary[i].setPos(x, y);
	}

	sort(ary, ary + N, cmp);

	for (int i = 0; i < N; i++)
	{
		ary[i].printInfo();
	}


	delete[] ary;


	return 0;
}