#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    /*
    설계:
        1. 모든 문자를 큐에 넣는다.
        2. 앞에서부터 빼면서, 짝을 지어주면서 큐에서 뺀다.
        3. 다 짝지어지면 true, 아니면 false 반환
    */
    
    queue<char> q;
    for(char c : s){
        q.push(c);
    }
    
    int left = 0;   // (의 수 저장
    int right = 0;  // )의 수 저장
    char mode = ' '; // 현재 필요한 괄호의 상태를 체크하기 위한 변수, L,R 사용
    bool check = false;
    while(!q.empty()){
        char cur = q.front();
        q.pop();
        
        // 모드 관리
        if(check == false){
            check = true;
            
            if(cur=='(') mode = 'L';
            else if(cur==')') mode = 'R';
            
        } else if(check == true){
            
            if(left ==0 && cur== ')'){
                mode = 'R';
            }
            
        }
        
        // 괄호 수 상태 관리
        if(cur == '(') left++;
        if(cur== ')') right++;
        
        // 짝 지어주기
        if(mode == 'L'){
             if(right >0){
                 left--;
                 right--;
             }
        }
        
    }
    
    if(left>0 || right >0) answer = false;

    return answer;
}