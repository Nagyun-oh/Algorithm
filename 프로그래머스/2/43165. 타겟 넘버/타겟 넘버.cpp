#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers,int target, int idx, int sum){
    
    if(idx==numbers.size()){
        return sum==target ? 1:0;
    }
    
    return dfs(numbers,target,idx+1,sum+numbers[idx])
        + dfs(numbers,target,idx+1,sum-numbers[idx]);
}


int solution(vector<int> numbers, int target) {
    
  /* 
    문제 조건:
       - numbers[] : 사용할 수 있는 숫자가 담긴 배열
       - target : 타겟 넘버
       - 정답 : 타겟 넘버를 만드는 방법의 수
       
    제한 사항: 
       - 20<= numbers.size() <= 20
       - 각 숫자는 1<= numbers[i] <=50 인 자연수
       - 1 <= target <= 1000
       
    로직 정리:
       - 모든 방법의 수를 구해야 하므로, 백트래킹 방식 (DFS)
       - 또한 연산(더하기/빼기)를 수행해야 하는 로직이 있어야함
  */
    
    int answer = 0;
    int idx = 0,sum=0;
    
    answer = dfs(numbers,target,idx,sum);
      
    return answer;
}