#include <iostream>
#include <queue>
using namespace std;

int n; // 다리를 건너는 트럭의 수
int w;  // 다리의 길이
int L; // 다리의 최대하중
int Truck[1000]; // 트럭의 무게에 대한 배열
int weight;
queue<int> q;
void init();
void method();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	method();

	return 0;
}


void init()
{
	
	cin >> n >> w >> L;
	weight = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> Truck[i];
		weight += Truck[i];
	}
	

}
void method()
{
	// 동시에 다리 위에 올라가있는 트럭들의 무게 합은 L보다 작아야한다.
	// 무게가 L보다 작은 경우에는 복수의 트럭이 건널 수 있다.
	// 그림과 트럭이 움직이는 방식을 보면, FIFO  --> Queue 사용
	int count = 0;
	int on_bridge_weight = 0;
	for (int i = 0; i < n; i++)
	{
	
		while (true)
		{
			if (q.size() == w)
			{
				on_bridge_weight -= q.front();
				q.pop();
			}
			if (on_bridge_weight + Truck[i] <= L)
			{
				break; 
			}
			else
			{
				q.push(0); // 무게가 L을 넘는경우 , 0을 삽입하지 않으면, if (on_bridge_weight + Truck[i] <= L) 에 걸리지않아서  while문 탈출이 안됨
				count++;
			}
		}
		q.push(Truck[i]);
		on_bridge_weight += Truck[i];
		count++;
		
	}

	cout << count + w;

}