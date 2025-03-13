#include <iostream>
#include <algorithm>
using namespace std;
// 8x8 크기를 "아무데서나" 고른다 -> 이게 뭔 뜻이지
// 진짜 랜덤하게 뽑으라는 건가
// "최소 개수" 구하는 거구나

string ch1[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};



string ch2[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

int search1(int y, int x,char** input)
{
	int count = 0;
	
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (input[y + i][x + j] != ch1[i][j])
				{
					count++;
				}
			}
		}


		return count;
}
	
int search2(int y, int x, char** input)
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (input[y + i][x + j] != ch2[i][j])
			{
				count++;
			}
		}
	}


	return count;
}


int main()
{
	
	//입력
	int N, M;
	cin >> N >> M;

	//체스판 만들기
	char** input= new char* [N];
	for (int i = 0; i < N; i++)
	{
		input[i] = new char[M];
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> input[y][x];
		}
	}
	
	int MIN = 12345;
	
	for (int i = 0; i + 8 <= N; i++)
	{
		for (int j = 0; j + 8 <= M; j++)
		{
			int tmp = min(search1(i, j, input), search2(i, j, input));
			if (tmp < MIN)
			{
				MIN = tmp;
			}
		}
	}

	cout << MIN;

	
	
	return 0;
}