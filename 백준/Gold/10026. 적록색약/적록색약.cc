#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int cnt1 = 0;
int cnt2 = 0;
int N;
char area[101][101];
int visit[101][101] = { 0, };
queue<pair<int, int>>q;

int direct[4][2] = {
    -1,0, //상
    1,0, //하
    0,-1, // 좌
    0,1 // 우
};

// 정상인인 경우 dfs
void bfs(int y, int x) {
    visit[y][x] = 1;

    q.push({ y,x });
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + direct[i][0];
            int dx = xx + direct[i][1];

            if (dy >= 0 && dy < N && dx >=0 && dx < N) {
                if (!visit[dy][dx]&&area[dy][dx]==area[y][x]) {
                    visit[dy][dx] = 1;
                    q.push({ dy,dx });
                }
            }

        }

    }
}

int main() {

    //입력 처리
    
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
                bfs(i, j);
                cnt1++;
            }
        }
    }

    memset(visit, 0, sizeof(visit));

    // 적록색맹인 경우 : R=G
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (area[i][j] == 'G')area[i][j] = 'R';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                bfs(i, j);
                cnt2++;
            }
        }
    }

    //결과 출력
    cout << cnt1 << " " << cnt2;

}