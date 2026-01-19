#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    auto it = str_list.begin();
    
    while(it!=str_list.end()){
        
        if(*it=="l"){
            answer = vector<string>(str_list.begin(),it);
            break;
        }
        
        if(*it=="r"){
            answer = vector<string>(it+1,str_list.end());
            break;
        }
        it++;
    }
    return answer;
 }