#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    /*
    설계:
        1. commands[i]의 각 행에 주어진 i,j,k에 대해서 array를 i~j번째를 자른다.
        2. 자른 배열을 오름차순으로 정렬한다.
        3. k번째 숫자를 answer배열에 저장한다.
    */
    
    vector<int> temp;
    for(int cur=0;cur<commands.size();cur++){
        temp.clear();
        // -1해서 값 보정
        int i = commands[cur][0]-1;
        int j = commands[cur][1]-1;
        int k = commands[cur][2]-1;
        
        // 1. commands[i]의 각 행에 주어진 i,j,k에 대해서 array를 i~j번째를 자른다.
        for(int a = i;a<=j;a++){
            temp.push_back(array[a]);
        }
        
        // 2. 자른 배열을 오름차순으로 정렬한다.
        sort(temp.begin(),temp.end());
        
        // 3. k번째 숫자를 answer배열에 저장한다.
        answer.push_back(temp[k]);
    }
    
    return answer;
}