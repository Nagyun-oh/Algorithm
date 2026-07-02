#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    /*
        설계:
            1. 각 작업이 몇일에 끝나는지 계산해서, 따로 배열에 저장해둔다.
            2. 기능 순서 및 작업 소요 시간에 맞게 배열에 저장한다.
    */
      
    // 1. 각 작업이 몇일에 끝나는지 계산해서, 따로 배열에 저장해둔다.
    vector<int> workTime;
    int len = progresses.size();
    for(int i=0; i<len; i++){
        int endDay = ceil((100 - progresses[i]) / (double)speeds[i]);
        workTime.push_back(endDay);
    }
    
    // 2. 기능 순서 및 작업 소요 시간에 맞게 배열에 저장한다.
    // 앞뒤 관계를 따져야 하니까, progresses 배열과 workTime 배열을 같이 사용해서 구해야 할듯
    // 그리고 앞에 있는 작업이 먼저 수행되어야 하니까 큐를 쓰면 될거같은데
   
    queue<int> q;
    for(int x : progresses){
        q.push(x);
    }
    
    int cnt = 0;
    int works = 0;
    int idx = 0;
    while(!q.empty()){
        cnt++;      
        
        while((idx<len) &&workTime[idx] <= cnt ){
            q.pop();
            works++;
            idx++;
        }
        
        if(works>0) {
            answer.push_back(works);
             works = 0;
        }
    
    }
    
    return answer;
}