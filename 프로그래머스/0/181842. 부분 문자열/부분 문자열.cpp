#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    auto it = str2.find(str1);
    // str1이 str2의 부분 문자열이면,
    if(it!=string::npos){
        answer = 1;
    }
    return answer;
}