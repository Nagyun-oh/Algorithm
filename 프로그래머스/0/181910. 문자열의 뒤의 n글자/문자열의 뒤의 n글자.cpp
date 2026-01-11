#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int idx =  my_string.size()-n; // 시작 위치
    for(int i=0;i<n;i++){
        answer.push_back(my_string[i+idx]);
    }
    return answer;
}