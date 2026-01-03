#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    int idx = 0;
    
    for(int i=0; i<myString.size();i++){
        if(myString[i]=='x'){
            answer.push_back(idx);
            idx = 0;
        }
        else idx++;
    }
    answer.push_back(idx);
    
    return answer;
}