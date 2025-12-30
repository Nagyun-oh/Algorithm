#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    for(int i=0;i<str_list.size();i++){
        auto it = str_list[i].find(ex);
        if(it==string::npos){
              answer+=str_list[i];  
        }
    }
    
    return answer;
}