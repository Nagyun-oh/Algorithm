#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
   
    for(int i=0;i<query.size();i++){
        int idx = query[i];
        if(i%2==0){
            arr.erase(arr.begin()+idx+1,arr.end());
        }else {
            arr.erase(arr.begin(),arr.begin()+idx);
        }
    }
    
    
    
    return arr;
}