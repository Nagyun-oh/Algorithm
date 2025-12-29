#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    for(int i=0;i<myString.length();i++){
        if(myString[i]=='A')myString[i] = 'B';
        else if(myString[i]=='B')myString[i] = 'A';
    }
    
    if(myString.find(pat) != string::npos) answer = 1;
    else answer = 0;
    
    return answer;
}