#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int> max_heap; // 최대 힙 (루트가 최대인 우선순위 큐)

// heap에서의 대소관계는 일반적인 sort랑 반대로 생각하자. (tree구조상 )
struct cmp{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b))return a > b; // 절대값이 같은 경우 작은값으로 
		else return abs(a) > abs(b); // 다른경우에느 절대값이 작은 원소로 
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, cmp> min_heap; // 최소 힙 (루트가 최소인 우선순위 큐)
	vector<int> v;
	int N; int x;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> x;
	
		if (x == 0) {
			if (min_heap.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back(min_heap.top());
				min_heap.pop();
			}
		}
		else {
			// x가 0이 아니면 push
			min_heap.push(x);
		}
	}

	for (const auto& a : v) {
		cout << a<<'\n';
	}

}