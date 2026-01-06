#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 소문자로 통일
void exchange(string& str){
    
    for(int i = 0; i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z') str[i] +=32;
    }
    
}

int solution(string myString, string pat) {
    int answer = 0;
    exchange(myString);
    exchange(pat);
    
    if(myString.find(pat)!=string::npos)answer = 1;
    
    return answer;
}