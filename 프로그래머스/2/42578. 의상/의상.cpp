#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string,int> hashTable;
    int ans = 1;
    
    for(int i=0;i<clothes.size();i++){
        string category = clothes[i][1];
          
        hashTable[category]++;
    }
    
   
    for(auto item: hashTable){
        ans *=(item.second +1);
    }
    
    ans--; // 다 안입는경우 빼기 (옷을 최소 1개는 입어야하므로)
    
    return ans;
    
    
}