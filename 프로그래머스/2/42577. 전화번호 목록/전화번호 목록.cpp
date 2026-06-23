#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 주어진 phone_book 배열의 길이가 1~1,000,000이므로, 브루트 포스로 푸는건 불가능함

bool solution(vector<string> phone_book) {
    
    unordered_map<string,int> hash;
    
    for(string str : phone_book){
        hash[str] = 1;
    }
    
    // 전화번호의 길이가 20이므로, 이를 이용해 풀면된다.
    // prefix 방식으로 해결
    for(string str : phone_book){
        
        string prefix = "";
        for(int j=0;j<str.length()-1;j++)
        {
            prefix +=str[j];
            if(hash.find(prefix) != hash.end()){
                return false;
            }
        } 
    }
    
    return true;   
}