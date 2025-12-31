#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    sort(num_list.begin(),num_list.end(),greater<>());
    for(int i=0;i<5;i++){
        num_list.pop_back();
    }
    
    sort(num_list.begin(),num_list.end());
    answer = num_list;
    return answer;
}