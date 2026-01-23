#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int row = arr.size();
    int col = arr[0].size();
    int n = max(row,col);
    vector<vector<int>> answer(n,vector<int>(n,0));
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            answer[i][j] = arr[i][j];
        }
    }
    
    
    return answer;
}