#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;

char area[101][101];
int visit[101][101] = { 0, };

int direct[4][2] = {
    -1,0, //상
    1,0, //하
    0,-1, // 좌
    0,1 // 우
};

// 정상인인 경우 dfs
void dfs(int y, int x) {
    
    visit[y][x] = 1;
 

    for (int i = 0; i < 4; i++) {
        int dy = y + direct[i][0];
        int dx = x + direct[i][1];

        if (!visit[dy][dx] && area[dy][dx] == area[y][x]) {
            visit[dy][dx] = 1;//방문처리
            dfs(dy, dx);
        }

    }

}

// 적록색맹인 경우 dfs
void dfs2(int y, int x) {

    visit[y][x] = 1;


    for (int i = 0; i < 4; i++) {
        int dy = y + direct[i][0];
        int dx = x + direct[i][1];

        if (!visit[dy][dx]) 
        {
            // 탐색 시작점이 R인 경우
            if (area[y][x] == 'R') {
                if ((area[dy][dx] == 'R') || area[dy][dx] == 'G') {
                    visit[dy][dx] = 1;//방문처리
                    dfs2(dy, dx);
                }
            }
            //  G인경우
            else if (area[y][x] == 'G') {
                
                if (area[dy][dx] == 'G' || area[dy][dx] == 'R') {
                    visit[dy][dx] = 1;//방문처리
                    dfs2(dy, dx);
                }
            }
            else { 
                // B인경우
                if (area[dy][dx] == area[y][x]) {
                    visit[dy][dx] = 1;
                    dfs2(dy, dx);
                }
            }
                  
        }

    }
}

int main() {

    //입력 처리
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> area[i][j];
        }
    }

    // 정상인인 경우 : cnt1에 결과 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                dfs(i, j);
                cnt1++;
            }
        }
    }

    memset(visit, 0, sizeof(visit));

    // 적록색맹인 경우 : cnt2에 결과 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                dfs2(i, j);
                cnt2++;
            }
        }
    }

    //결과 출력
    cout << cnt1 << " " << cnt2;

}