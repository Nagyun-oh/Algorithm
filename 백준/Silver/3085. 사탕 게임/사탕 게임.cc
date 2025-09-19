#include <iostream>
#include <algorithm>
using namespace std;

int N;
int max_count = 0;
char board[51][51];

void init();
void solve();
void check_row();
void check_col();

// 인접한 사탕 바꿀때마다 행 별로  최대 사탕 개수 체크
void check_row()
{
	for (int y = 0; y < N; y++)
	{
		int count = 1;
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == board[y][x + 1])count++;
			else
			{
				if (count > max_count)max_count = count; // 최대 개수 갱신
				count = 1;
			}

		}
	}

}

void check_col()
{
	for (int x = 0; x < N; x++)
	{
		int count = 1;
		for (int y = 0; y < N; y++)
		{
			if (board[y][x] == board[y+1][x ])count++;
			else
			{
				if (count > max_count)max_count = count;
				count = 1;
			}
		}
	}

}


void init()
{
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x]; // input : C,P,Z,Y 
		}
	}
}

// 빙고 게임인듯
// 교환하면서 확인
// 입력 크기가 작아서 브루트 포스로 풀면됨 
void solve()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			// 인접한 열끼리 바꾸고 최대 개수 갱신
			if (x < N - 1) {
				swap(board[y][x], board[y][x + 1]);
				check_row();
				check_col();
				swap(board[y][x], board[y][x + 1]); // 원위치로 되돌리기 ( 문제 설명이 인접한 두칸을 고른다 -> 교환 -> 가장 긴 부분 먹는다 ) 이기때문에
			}
			// 인접한 행끼리 바꾸고 최대 개수 갱신 
			if (y < N - 1) {
				swap(board[y][x], board[y + 1][x]);
				check_row();
				check_col();
				swap(board[y][x], board[y + 1][x]); // 원위치로 되돌리기 
			}
		}
	}


	cout << max_count;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();


}