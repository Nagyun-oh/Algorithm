#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    
    // 처음에는 다리 전체가 빈 공간
    for(int i=0;i<bridge_length;i++){
        bridge.push(0);
    }
    
    int currentWeight = 0;
    int truckIndex = 0;
    int truckCount = truck_weights.size();
    
    while(truckIndex < truckCount || currentWeight >0){
        
        // 다리 맨 앞의 트럭 또는 빈 공간이 빠져나감
        currentWeight -=bridge.front();
        bridge.pop();
        answer++;
        
        // 다음 트럭을 올릴 수 있는지 확인
        if(truckIndex < truckCount && 
          currentWeight + truck_weights[truckIndex] <= weight){
            
            currentWeight +=truck_weights[truckIndex];
            bridge.push(truck_weights[truckIndex]);
            truckIndex++;
        }else {
            // 트럭을 올릴 수 없으면 빈 공간 추가
            bridge.push(0);
        }
    }
    
    return answer;
}