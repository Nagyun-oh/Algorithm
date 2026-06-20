#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int hashTable[100001];

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string,int> m;
    
    for(string str: completion){
        m[str]++;
    }
    
    for(string str:participant){
        if(m[str]==0){
            return str;
        }
        m[str]--;
    }
         
    return "";
}