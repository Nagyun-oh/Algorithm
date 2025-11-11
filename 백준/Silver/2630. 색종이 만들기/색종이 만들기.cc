#include <iostream>

using namespace std;

#define MAX_SIZE 129
int ary[MAX_SIZE][MAX_SIZE];
int N;
int white = 0; int blue = 0;

void recur(int dy,int dx,int size)
{
	bool cut = false; // N/2 x N/2로 잘라야되는지 판단하는 변수
	int first_color = ary[dy][dx]; // 시작 위치 색깔

	for (int y = dy; y < dy + size; y++)
	{
		for (int x = dx; x < dx + size; x++)
		{
			if(first_color != ary[y][x])
			{
				cut = true;
				break;
			}				
		}
		if (cut)break;
	}

	if (cut) 
	{
		recur(dy, dx, size / 2);
		recur(dy, dx + size / 2, size / 2);
		recur(dy + size / 2, dx, size / 2);
		recur(dy + size / 2, dx + size / 2, size / 2);
	}
	else
	{
		if (first_color == 1)blue++;
		else white++;
	}
}

int main()
{
// ===== 입력 처리======

	cin >> N;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> ary[y][x];
		}
	}

//==== solve=====
// 결국 배열의 크기를 1/2씩 줄여가면서, 검증을 해야함
// 이때 검증은 배열의 크기가 1이 되는 경우 또는 배열의 색깔이 통일된 경우 멈춤

	// 재귀함수로 처음에 네 부분 나눠서 검증 마치면 리턴되게 설정
	recur(1, 1, N);

	cout << white << '\n';
	cout << blue;


	return 0;
}

