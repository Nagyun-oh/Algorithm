#include <iostream>
#include <queue>
using namespace std;

int A, B;
queue<pair<long, int>>q;

void bfs()
{
	q.push({ A,1 });
	while (!q.empty()) {
		long Res = q.front().first;
		int cnt = q.front().second;
		q.pop();

		long multiRes = Res * 2;
		long addOne = Res*10 + 1;

		if (multiRes == B || addOne == B) {
			cout << cnt+1;
			return;
		}

		if(multiRes<B)q.push({ multiRes,cnt + 1 });
		if (addOne < B)q.push({ addOne,cnt + 1 });

	}

	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> A >> B;
	bfs();
	
}