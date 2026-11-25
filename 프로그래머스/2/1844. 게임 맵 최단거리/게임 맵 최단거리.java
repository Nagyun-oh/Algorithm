import java.util.Queue;
import java.util.ArrayDeque;

// bfs 로 풀면됨
class Solution {
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        
        int direct[][] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상,하,좌,우
        boolean[][] visited = new boolean[n][m];
        
        // 1) 큐 생성 {d}
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{0,0,1}); // {y,x,이동거리}
        visited[0][0] = true;
        
        // 2) bfs 순회 및 최단거리 찾기
        while(!q.isEmpty()){
            
            int[] current = q.poll();
            int y = current[0];
            int x = current[1];
            int distance = current[2];
            
            // bfs는 도착하는 순간 최단거리
            if(y==n-1 && x ==m-1){
                return distance;
            }
            
            // 벽이 없는 곳으로만 이동 가능
            for(int i=0;i<4;i++){
                int dy = y+direct[i][0];
                int dx = x+direct[i][1];
                
                // 경계 체크
                if(dy<0 || dy>=n || dx<0 || dx>=m){
                    continue;
                }
                
                // 벽이 없고, 방문하지 않았다면 이동
                if(maps[dy][dx] == 1 && !visited[dy][dx]){
                    visited[dy][dx] = true;
                    q.offer(new int[]{dy,dx,distance+1});
                }
            }
        }
        return -1;
    }
     
}