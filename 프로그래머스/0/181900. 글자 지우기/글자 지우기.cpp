#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    int flag = 0;
    sort(indices.begin(),indices.end());
    for(int i=0;i<my_string.size();i++){
        flag = 0;
    for(int j=0;j<indices.size();j++){
        if(i==indices[j]) {
            flag = 1;
        }
    }
        if(!flag) answer+=my_string[i];
    }
    return answer;
}