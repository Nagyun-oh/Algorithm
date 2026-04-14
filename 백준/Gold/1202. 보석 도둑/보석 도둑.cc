#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct jewly {
	int weight;
	int price;
};

vector<jewly> v;	// 각 보석에 대한 정보
vector<int> c;	// 각 가방에 담을 수 있는 최대 무게 
vector<int> used;

int N,K;// 보석 N개, 가방 K개

bool comp(jewly a, jewly b) {
	return a.weight < b.weight;
}


int main() {
	ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	/* Input */
	cin >> N >> K;	
	v.resize(N);
	c.resize(K);
	used.resize(K,0);
	
	// 각 보석의 정보 (무게, 가격) :  v
	for (int i = 0; i < N; i++) {
		cin >> v[i].weight >> v[i].price;
	}
	// 각 가방에 담을 수 있는 최대 무게 : c
	for (int i = 0; i < K; i++) {
		cin >> c[i];
	}

	/* solve */
	// 1. 보석 정보 배열 (v) , 가방 최대 무게 배열 (c)를 오름차순으로 정렬
	sort(v.begin(), v.end(), comp);	// O (NlogN)
	sort(c.begin(), c.end());	// O(KlogK)

	// 2. 작은 무게의 보석이 작은 용량의 가방에 넣게 계산 
	// 힌트를 통해, 그리디 알고리즘을 사용함을 알 수 있다.
	priority_queue<int> pq;	// price를 담는 최대 힙
	long long max_price = 0;
	int jewel_idx = 0;
	// 작은 가방부터 하나씩 확인
	for (int i = 0; i < K; i++) {

		// 현재 가방 c[i]에 담을 수 있는 모든 보석의 가치를 큐에 삽입
		while (jewel_idx < N && v[jewel_idx].weight <= c[i]) {
			pq.push(v[jewel_idx].price);	// O(logN)
			jewel_idx++;
		}

		// 큐의 맨 위에는 현재 가방에 넣을 수 잇는 가장 비싼 보석이 있음
		if (!pq.empty()) {
			max_price += pq.top();
			pq.pop();
		}
	}
	// O((N+K)log N + Klog N)
	// -> O((N+K)logN))
	
	// 3. 얻은 보석의 최대 가격 출력하기
	cout << max_price;
}