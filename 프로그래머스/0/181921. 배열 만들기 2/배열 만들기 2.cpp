#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i=l;i<=r;i++){
        string s = to_string(i);
        bool check = false;
        
        for(char c : s){
            if(c!='0' && c!='5'){
                check = true;
                break;
            }
        }
        
        if(!check)answer.push_back(stoi(s));
        
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    
    return answer;
}