#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for(string str : picture){
        string temp ="";
        int len = str.size();
            for(int t=0;t<len;t++){
                for(int a = 0;a<k;a++){
                    temp+= str[t];
                }
            }
            for(int j=0;j<k;j++){
                answer.push_back(temp);
            }
    }
    
    
    return answer;
}