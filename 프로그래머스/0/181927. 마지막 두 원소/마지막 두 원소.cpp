#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int a = 0;
    int back = num_list[num_list.size()-1];
    int prev_back = num_list[num_list.size()-2];
    
    if(back>prev_back) a = back-prev_back;
    else if(back <= prev_back) a = back * 2;
    
    num_list.push_back(a);
    answer = num_list;
    
    return answer;
}