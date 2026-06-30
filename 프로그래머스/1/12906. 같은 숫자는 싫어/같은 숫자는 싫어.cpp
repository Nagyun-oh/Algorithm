#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 처음 배열의 순서를 유지해야 하므로, 큐 사용해야할듯
/*
    1. 큐에 배열을 넣는다
    2. 큐에 존재하면 넣지 않는다.
    3. 큐의 값을 차례대로 answer배열에 담는다.
    4. answer 반환
*/

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    queue<int> q;
    
    int prev = 10;
    for(int value : arr){
        // 이전값과 다르면 큐에 넣기
        if(prev != value){
            q.push(value);
        }
        
        // 이전값 설정
        prev = value;
    }
    
    while(!q.empty()){
        int value = q.front();
        q.pop();
        
        answer.push_back(value);
    }
    
    return answer;
}