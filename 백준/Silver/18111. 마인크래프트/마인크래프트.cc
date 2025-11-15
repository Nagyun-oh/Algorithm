#include<iostream>
#include <climits> // for INT_MAX
using namespace std;  // 13:50

#define MAX 501

int N, M, B;
int arr[MAX][MAX];

void init()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}

// 1. 좌표 (i,j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣기 ( 2초 )
// 2. 인벤토리에서 블록 하나를 꺼내어서 좌표 (i,j)의 가장 위에 있는 블록위에 놓기 (1초)

// 블록이 없을 경우에는 제거해서 맞춰야하고, 블록개수가 맞게 존재하면, 쌓아서 맞춘다.
// 이때 더 적게 걸리는 경우를 찾아야한다.
// 최소 시간 , 땅의 높이 구하기
void solve()
{
	int MinTime = INT_MAX; int FindHeight = 0;
	
	// 0 ~ 256 높이의 블록 모두 맞춰보면서, 최적의 값 찾기
	for (int height = 0; height <= 256; height++)
	{
		int Time = 0; int Blocks = B;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				int CurHeight = arr[i][j];

				// 현재 기준되는 높이보다 크면, 블록을 제거해준다. (2s)
				if (CurHeight > height)
				{
					Time += (CurHeight - height) * 2;
					Blocks += (CurHeight - height);
				}
				// 현재 기준되는 높이보다 작으면, 블록을 놓는다. (1s)
				else if (CurHeight < height)
				{
					Time += height - CurHeight;
					Blocks -= height - CurHeight;
				}
			}
		}
		// 해당 기준 블록에 대해서, 인벤토리에 있는 블록 수가 음수이면, 다음 기준 블록으로 넘기기
		if (Blocks < 0)continue;

		// 그렇지 않다면,최소 시간 및 높이 갱신해주기
		if (Time <= MinTime) {
			MinTime = Time; //최소 시간 갱신
			FindHeight = height; // 높이 갱신
		}

	}

	cout << MinTime << " " << FindHeight;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	init();
	solve();

}