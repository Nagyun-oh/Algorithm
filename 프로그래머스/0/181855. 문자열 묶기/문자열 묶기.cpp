#include <string>
#include <vector>

using namespace std;
int hashTable[100001] = {0,};

int solution(vector<string> strArr) {
    int answer = 0;
    int len = strArr.size();
    
    for(int i=0;i<len;i++){
        hashTable[strArr[i].length()]++;
    }
    
    for(int i=0;i<len;i++){
        if(hashTable[strArr[i].length()]>=answer){
            answer = hashTable[strArr[i].length()];
        }
    }
    
    
    return answer;
}