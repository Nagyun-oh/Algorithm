#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    for(string str : order){
        bool checkAmericano = str.find("americano")!=string::npos; // 아메리카노인 경우 true
        bool checkCafelatte = str.find("cafelatte")!=string::npos; // 아메리카노인 경우 true
        bool checkAnything = str.find("anything")!=string::npos; // anything인 경우 true
        if(checkAnything){
            answer += 4500; // 아무거나인 경우 차가운 아메리카노로 통일
        }else if(checkAmericano){
            answer +=4500;
        }else if(checkCafelatte){
            answer +=5000;
        }
    }
    
    return answer;
}