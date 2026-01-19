#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    int hash_table[123]={0,};
    for(int i=0;i<my_string.size();i++){
        hash_table[my_string[i]]++;    // 대문자가 65~90 소문자가 97 ~ 122 
    }
    
    for(int i=65;i<=90;i++){
        answer.push_back(hash_table[i]);
    }
     for(int i=97;i<=122;i++){
        answer.push_back(hash_table[i]);
    }
    
    return answer;
}