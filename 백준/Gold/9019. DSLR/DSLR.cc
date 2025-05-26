#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

void init();
void method();

int A, B;
int T;
bool visited[10001];
queue<pair<int, string>> q; // <n, 출력문>

// 최소 명령어 찾기니까 BFS일거같은데

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	return 0;
}

void init()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		method();
		memset(visited, 0, sizeof(visited));
		while (!q.empty())q.pop();
	}
	
}

// BFS
void method()
{
	q.push({ A,"" });
	visited[A] = true;
	
	while (!q.empty())
	{
		int num = q.front().first;
		string operation = q.front().second;
		q.pop();

		if (num == B)
		{
			cout << operation << '\n';
			return;
		}
		
		int temp =0;

		// D
		temp = (2 * num) % 10000;
		if (!visited[temp])
		{
			visited[temp] = 1;
			q.push({ temp,operation + "D" });
		}

		// S
		temp = num - 1;
		if (temp == -1)temp = 9999;
		if (!visited[temp])
		{
			visited[temp] = 1;
			q.push({ temp,operation + "S" });
		}

		// L 
		temp = (num % 1000) * 10 + (num / 1000);
		if (!visited[temp])
		{
			visited[temp] = 1;
			q.push({ temp,operation + "L" });
		}

		// R
		temp = (num % 10) * 1000 + num / 10;
		if (!visited[temp])
		{
			visited[temp] = 1;
			q.push({ temp,operation + "R" });
		}

	}
}


