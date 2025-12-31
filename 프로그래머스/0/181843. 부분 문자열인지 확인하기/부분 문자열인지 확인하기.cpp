#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    auto it = my_string.find(target);
    if(it!=string::npos){
        answer = 1;
    }
    return answer;
}