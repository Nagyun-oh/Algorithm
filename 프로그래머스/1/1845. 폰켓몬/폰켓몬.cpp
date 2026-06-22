#include <vector>
#include <unordered_map>
using namespace std;

// N마리 폰켓몬의 종류 번호가 담긴 배열 nums가 매개변수로 주어질 때,
// N/2마리의 폰켓몬을 선택하는 방법 중, 가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아,
// 그때의 폰켓몬 종류 번호의 개수를 return 하도록 solution 함수를 완성해주세요.

bool hashTable[200001];

int solution(vector<int> nums)
{
    unordered_map<int,int> m;
    
    int cnt = 0; // N/2 마리 채웠는지 확인하기 위한 변수
    int maxCnt = nums.size()/2; // nums의 길이는 항상 짝수로 주어지므로, 홀수는 고려하지 않아도됨.
    int types = 0;  // 폰켓몬 종류 번호의 개수
    int maxTypes = 0;
    
    for(int idx : nums){
        
        // 최대 종류수를 구해놓자.
        if(hashTable[idx]==false)
        {
            maxTypes++;
        }
        
        m[idx]++;
        hashTable[idx] = true;
    }
    
    
    
    for(int idx : nums){
        
        // N/2마리 채웠으면 종료
        if(cnt==maxCnt){
            break;
        }
        
        // 사용하지 않은 종류가 우선순위를 가짐
        if(hashTable[idx] && m[idx] >0)
        {
            hashTable[idx] = false;
            m[idx]--;
            cnt++;
            types++;
        }
        // 사용한 종류일 경우, 종류 번호의 개수는 증가x
        else if(types < maxTypes){
            continue;
        }
        else 
        {
            cnt++;
            m[idx]--;
        }    
    }
    
    return types;  
}