#include <string>
#include <vector>

using namespace std;

int visited[100001] = {0,};

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for(int i=0;i<arr.size();i++){
        if(answer.size()==k)break;
        
        if(!visited[arr[i]]){
            visited[arr[i]] = 1;
            answer.push_back(arr[i]);
        }else continue;
    }
    
    // 완성된 배열의 길이가 k보다 작을 경우
    while(answer.size()!=k){
        answer.push_back(-1);
    }
    
    return answer;

}