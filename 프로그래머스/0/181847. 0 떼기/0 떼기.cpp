#include <string>
#include <vector>


using namespace std;

string solution(string n_str) {
    string answer = "";
    int idx = 0;
    for(int i=0;i<n_str.length();i++){
        if(n_str[i]!='0') {
            idx = i;  
            break;
        }
   }
    
    for(int i=idx;i< n_str.length();i++){
        answer+=n_str[i];
    }
    
    
    return answer;
}