#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    
    for(int i=0;i<queries.size();i++){
        int st = queries[i][0];
        int end = queries[i][1];
        reverse(my_string.begin()+st,my_string.begin()+end+1);
    }
    return my_string;
}