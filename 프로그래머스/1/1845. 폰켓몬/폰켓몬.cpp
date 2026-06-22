#include <vector>
#include <unordered_map>
using namespace std;

// 종류 수와 최대 마리수의 교집합을 구해야한다.

int solution(vector<int> nums)
{
    unordered_map<int,int> hash;   
    
    for(int num : nums){
        hash[num]+=1;
    }
    
    return(min(hash.size(),nums.size()/2));
    
}