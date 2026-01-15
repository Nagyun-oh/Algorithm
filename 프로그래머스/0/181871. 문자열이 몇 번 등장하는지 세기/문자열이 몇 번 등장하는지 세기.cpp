#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    
    int answer = 0; 
   
    size_t pos = myString.find(pat);
    size_t last = string::npos;
    if(pos==string::npos)return answer;
    
    answer++;
    while(true){
        last = pos;
        pos = myString.find(pat,last+1);  
        if(pos==string::npos)break;
        answer++;
    }
    
    return answer;
}