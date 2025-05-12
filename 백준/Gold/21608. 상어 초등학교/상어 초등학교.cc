#include <iostream>

// 조건 1: 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정함
// 조건 2: 1을 만족하는 칸이 여러개 이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 정함
// 조건 3: 2를 만족하는 칸도 여러개이면 행의 번호가 가장 작은칸으로
// 조건 4: 3을 만족하는 칸도 여러개이면, 열의 번호가 가장 작은 칸으로

// 만족도 => 인접한 좋아하는 학생 0 이면 만족도 == 0
//        => 인접한 좋아하는 학생 1 이면 만족도 == 1
//        => 인접한 좋아하는 학생 2 이면 만족도 == 10
//        => 인접한 좋아하는 학생 3 이면 만족도 == 100
//        => 인접한 좋아하는 학생 4 이면 만족도 == 1000
#define fast ios::sync_with_stdio(),cin.tie(0),cout.tie(0);

using namespace std;

// ==== direction table====
int direct[4][2] =
{
	0,-1,   // 왼쪽
	0,1,    // 오른쪽
	1,0,   // 아래
	-1,0   // 위
};

// =====parameter===========
int N;
int** classroom;
int LikeStudent[401][4];


// ======Function==========
void init(); // 입력 함수
void method(int currrent_Student); // 통합적으로 처리하는 함수
bool condition(int current_student,int y,int x); // 좋아하는 학생인지 판별
void Calculate_satisfy();

void init()
{
	cin >> N;
	//교실 만들기
	classroom = new int*[N];
	for (int i = 0; i < N; i++)
	{
		classroom[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			classroom[i][j] = 0;
		}
	}

	int total = N * N;
	
	for (int i = 0; i < total; i++)
	{
		int idx;
		cin >> idx;
		for (int i = 0; i < 4; i++)
		{
			cin >> LikeStudent[idx][i];
		}
		method(idx);
	}


}

void method(int current_student)
{
	int resX = -1, resY = -1; //최종적으로 학생을 앉힐 위치
	int MaxLikeStudent = -1; //  좋아하는 학생수 최대값
	int MaxEmpty = -1; //인접 빈칸 수 최대값

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int likestudent = 0;
			int empty = 0;

			if (classroom[y][x] > 0)continue; // 이미 자리 주인 있음

			// 자리 주인 없을 경우
			for (int i = 0; i < 4; i++)
			{
				int newY = y + direct[i][0];
				int newX = x + direct[i][1];
				bool InRange = (newY >= 0 && newY < N) && (newX >= 0 && newX < N);

				if (InRange)
				{
					if (classroom[newY][newX] == 0) 
					{
						empty++;
					}
					else if (condition(current_student,newY,newX))
					{
						likestudent++;
					}

				}
			}

			// 조건1
			if (likestudent > MaxLikeStudent)
			{
				MaxLikeStudent = likestudent;
				MaxEmpty = empty;
				resY = y;
				resX = x;
			}
			//조건2
			else if (likestudent == MaxLikeStudent)
			{
				if (empty > MaxEmpty)
				{
					MaxEmpty = empty;
					resY = y;
					resX = x;
				}
			}
			else if (empty == MaxEmpty)
			{
				//조건3
				 if (resY > y)
				 {
					resY = y;
					resX = x;
				 }
				 //조건4
				 else if (resY == y && resX > x)
				 {
					 resX = x;
				 }

			}
		}

	}

	classroom[resY][resX] = current_student; // 찾은 자리 앉히기

}

//좋아하는 학생인지 판별 
bool condition(int current_student, int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		if (LikeStudent[current_student][i] == classroom[y][x]) // 좋아하는 학생일경우
		{
			return true;
		}
	}
	return false; // 아닐경우

}

void Calculate_satisfy()
{
	int count = 0;

	//전체 학생 탐색
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int adjacent_friend = 0;

			// 해당 자리앉은 애의 좋아하는 인접한 친구 계산
			for (int i = 0; i < 4; i++)
			{
				int newY = y + direct[i][0];
				int newX = x + direct[i][1];

				bool InRange = (newY >= 0 && newY < N) && (newX >= 0 && newX < N);
				if (InRange)
				{
					if (condition(classroom[y][x], newY, newX))
					{
						adjacent_friend++; 
					}
				}
			}

			if (adjacent_friend == 1) count += 1;
			else if (adjacent_friend == 2)count += 10;
			else if (adjacent_friend == 3)count += 100;
			else if (adjacent_friend == 4)count+=1000;

		}
	}

	cout << count << '\n';

}


int main()
{
	fast;
	init();

	Calculate_satisfy();


	return 0;
}