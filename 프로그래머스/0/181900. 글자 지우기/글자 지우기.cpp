#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    for(int i : indices){
        my_string[i] = ' ';
    }
    
    for(const auto str : my_string){
        if(str !=' ') answer+=str;
    }
    
    return answer;
}