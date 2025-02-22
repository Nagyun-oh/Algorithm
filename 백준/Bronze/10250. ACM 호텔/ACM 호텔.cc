#include <iostream>
#include <string>
using namespace std;

int Hotel(int H, int W, int N)
{

	// 호텔 만들기
	int** hotel = new int* [H];
	for (int i = 0; i < H; i++)
	{
		hotel[i] = new int[W];
	}

	//호텔 방들이 초기에 비어있다고 가정
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			hotel[y][x] = 0;
		}
	}

	int count = 1;
	int flag = 0;
	// N번째 손님 전까지 채우기
	for (int x = 0; x < W; x++)
	{
		for (int y = H-1; y>= 0; y--)
		{
			if (count == N)
			{
				flag = 1;
				break;
			}
			hotel[y][x] = 1;
			count++;		
		}
		if (flag == 1) break;
		
	}

	int Y = 0;
	int X = 0;
	int result = 0;
	flag = 0;
	for (int x = 0; x<W; x++)
	{
		for (int y = H-1; y>=0; y--)
		{
			if (hotel[y][x] == 0)
			{
				Y = H - y;
				X = x + 1;

				string h, w;

				h = to_string(Y);

				if (X < 10)
				{
					string a, b;
					a = to_string(0);
					b = to_string(X);
					w = a + b;
				}
				else w = to_string(X);
				
				string res = h + w;
				result = stoi(res);

				flag = 1;
				break;
			}
		}
		if (flag)break;
	}

	return result;
}

int main()
{
	int T; // test case 수
	int H, W, N; // 층수, 각 층의 방 수, 몇번째 손님인지

	cin >> T;
	int* result = new int[T];
	

	for (int i = 0; i < T; i++)
	{
		cin >> H >> W >> N;

		result[i] = Hotel(H, W, N);
	}

	for (int i = 0; i < T; i++)
	{
		cout << result[i] << endl;
	}





	return 0;
}