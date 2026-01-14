#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    for(int i=0;i<my_string.size();i++){
        
        if(i==s){
            for(int j=e;j>=s;j--)
                answer +=my_string[j];
            i+=e-s;
            continue;
        }
       answer +=my_string[i];
        
    }
    
    return answer;
}