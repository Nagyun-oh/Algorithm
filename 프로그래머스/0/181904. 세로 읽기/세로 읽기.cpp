#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    int idx = c-1;
    
    for(int i=idx;i<my_string.size();i+=m){
        answer +=my_string[i];
    }
    return answer;
}