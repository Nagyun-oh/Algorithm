#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    /*
    해당 문제는 풀이에 대한 알고리즘이 문제 설명에 그대로 있어어 가져다 쓰자.
    설계:
        1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
        2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
        3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
        3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
    */
    
    // 정렬을 하면, 동작이 망가져서 안될거같고
    // 따라서, 2번 동작을 수행하기 위해서는 탐색이 필요한데 queue는 불가능하다. 따라서 deque를 써야할거같은데
    
    deque<pair<int,int>> deq; // <우선순위,인덱스>
    for(int i=0;i<priorities.size();i++){
        deq.push_back({priorities[i],i});
    }
    
    int count = 0;
    while(!deq.empty()){
        pair<int,int> cur = deq.front();
        deq.pop_front();
        
        bool isValueHigher = false;
        
        for(const auto& x : deq){
            if(x.first > cur.first){
                isValueHigher = true;
                break;
            }
        }
        
        if(isValueHigher){
            deq.push_back(cur);
        }else {
            answer++;
            
            if(cur.second == location){
                break;
            }        
        }     
    }
    
    return answer;
}