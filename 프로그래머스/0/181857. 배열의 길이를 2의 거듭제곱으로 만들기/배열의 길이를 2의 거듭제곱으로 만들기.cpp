#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {

    int len = 1;
    
    while(len<arr.size()){
        len*=2;
    }
    
    int dlen = len-arr.size();
    
    for(int i =0;i<dlen;i++)
        arr.push_back(0);
    
    return arr;
}