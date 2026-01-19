#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    vector<string> answer2;
    int flag = 0;
    int len = str_list.size()-1;
    for(int i=0;i<=len;i++){
        if(str_list[i]=="l") {
            return answer;
        }
        else if(str_list[i]=="r") {
            for(int j=i+1;j<=len;j++)answer2.push_back(str_list[j]);
            return answer2;
        }
        else {
            answer.push_back(str_list[i]);
        }
    }
    
    return {};
    
 }