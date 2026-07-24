#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    /* 
    문제 조건 정리
        - citations.size(): 논문의 수
        - citations[i] : 논문별 인용 횟수
        - "h번이상 인용된 논문이 h편이상" << 이걸 이용해서 h를 구해야 할 듯   
        - 1000 x 10,000 = 10,000,000 -> 브루트 포스 가능
    */
    
   /*
   Solve:
        1. h를 0부터 논문의 수까지 설정
        2. h를 하나씩 증가시켜가며 조건 만족시 h값 갱신
        3. 갱신시켜가며 h의 최댓값 구하기 (H-Index)
   */
    
    int answer = 0;
    
    int cnt;
    int rest;
    for(int h=0;h<=citations.size();h++){
        
        cnt = 0;
        rest = citations.size();
        
        for(int i=0; i<citations.size();i++){
            if(citations[i] >= h){
                cnt++;
                rest--;
            }
        }
        
        if(cnt >= h && rest <= h){
            answer = h;
        }
    }
    
    return answer;
}