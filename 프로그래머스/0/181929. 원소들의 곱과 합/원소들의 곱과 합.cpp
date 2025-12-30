#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mul =1;
    int sum_square = 0;
    for(int i : num_list){
        mul *=i;
        sum_square +=i;
    }
    sum_square *=sum_square;
    
    if(mul<sum_square)return 1;
    
    return answer;
}