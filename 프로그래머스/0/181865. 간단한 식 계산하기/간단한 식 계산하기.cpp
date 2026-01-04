#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    string tmp = "";
    
    string op="";
    int a = 0;
    
    for(int i=0;i<binomial.size();i++){
        if(binomial[i]>='0'&&binomial[i]<='9') tmp+=binomial[i];
        else if(binomial[i]!=' '){
            op+=binomial[i];
            answer +=stoi(tmp);
            tmp="";
        }
    }
    
    if(op == "+") answer += stoi(tmp);
    else if(op == "-") answer -= stoi(tmp);
    else if(op == "*") answer *= stoi(tmp);
    
    return answer;
}