#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> temp = arr;
    bool flag = 1;
    while(true){  
        flag = 1;
    for(int i=0;i<arr.size();i++){
        temp[i] = arr[i];
        if(arr[i]>=50&&arr[i]%2==0){   
            arr[i] = arr[i]/2;
        }
        else if(arr[i]<50 && arr[i]%2==1){
            arr[i] = arr[i]*2 +1;
        }
        if(temp[i]!=arr[i]) flag = 0;
    } 
        if(flag)break;
        answer++;
    }
    
    return answer;
}