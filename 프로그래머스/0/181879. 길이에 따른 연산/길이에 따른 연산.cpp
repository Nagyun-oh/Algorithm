#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer1 = 0;
    int answer2 = 1;
    int flag = 0;
    int len = num_list.size();
    if(len>=11){
        for(int i : num_list)  {
            answer1 +=i;
            flag = 1;
        }
    }else if(len<=10){
        for(int i: num_list){
            answer2 *=i;
            flag = 2;
        }
    }
    
    if(flag ==1) return answer1;
    else if(flag==2) return answer2;
    
}