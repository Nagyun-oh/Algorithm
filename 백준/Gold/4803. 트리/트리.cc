#include <iostream>

#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

using namespace std;

// 트리는 정점이 n개 간선이 n-1개이고, 사이클이 없는 연결 요소

int tree[501];
int x, y;
int testcase = 1; // case num
int Treecount = 0; // 트리 개수
int n; // 정점의 개수 n
int m; // 간선의 개수 m

int search(int x)
{
	if (tree[x] == x)
	{
		return x;
	}
	else {
		tree[x] = search(tree[x]);
		return tree[x];
	
	}

}

//간선 만들기
void Union(int x, int y)
{
	x = search(x);
	y = search(y);

	// 각각의 트리에 대한 루트 노드 설정
	if (x < y) {
		tree[y] = x;
	}
	else if (x > y) 
	{
		tree[x] = y;
	}
	else // 사이클이 발생한 경우 
	{
		tree[x] = 0;
		tree[y] = 0;
 	}

}

void method()
{
	// 각각의 정점에 대한 tree에 루트 노드 할당 
	for (int i = 1; i <= n; i++)
	{
		tree[i] = i;
	}

	// 간선 만들기 
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		Union(x, y);
	}
	// 트리 개수 확인
	for (int i = 1; i <= n; i++)
	{
		if (tree[i] == i)
		{
			Treecount++;
		}
	}


	// 출력
	cout << "Case " << testcase << ": ";

	if (Treecount == 0) cout << "No trees.\n";
	else if (Treecount == 1)cout << "There is one tree.\n";
	else cout << "A forest of " << Treecount << " trees.\n";

	testcase++;  // "Case (testcase) : " 증가
	Treecount = 0; // 다음 수행을 위해 트리 개수 0으로 초기화 
}

int main()
 {
	fast;

	while (true) 
	{
		cin >> n >> m;
		if (n == 0 && m == 0)break;  // 0 0 입력받으면 종료
		method();	
	}

	return 0;
}