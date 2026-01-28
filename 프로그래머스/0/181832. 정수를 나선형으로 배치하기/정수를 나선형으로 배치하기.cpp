#include <string>
#include <vector>

using namespace std;

int direct[4][2]={
    0,1,  // 오른쪽
    1,0,  // 아래
    0,-1, // 왼쪽
    -1,0 // 위
};

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n,0));
   
    int y = 0; int x = 0;
    int cycle = 0;
    for(int i=1;i<=n*n;i++){
        answer[y][x] = i;
        
        int ny = y + direct[cycle][0];
        int nx = x + direct[cycle][1];
        
        if(ny<0||ny>=n||nx<0||nx>=n||answer[ny][nx]!=0){
            cycle = (cycle+1)%4;
            ny = y + direct[cycle][0];
            nx = x + direct[cycle][1];
        }
        
        y = ny;
        x = nx;
        
    }
    
    
    return answer;
}