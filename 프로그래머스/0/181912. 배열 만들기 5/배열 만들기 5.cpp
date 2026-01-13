#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    string temp = "";
    for(string str : intStrs){
        temp = str.substr(s,l);
        int a = stoi(temp);
        if(a>k)answer.push_back(a);
    }
    return answer;
}