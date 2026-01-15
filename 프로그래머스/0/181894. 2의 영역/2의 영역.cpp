#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int start = 0;
    int end = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==2){
            start = i;
            break;
        }
    }
    
    for(int i=0;i<arr.size();i++){
        if(arr[i]==2)end = i;
    }
    
    if(end==0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=start;i<=end;i++){
        answer.push_back(arr[i]);
    }

    
    return answer;
}