
class Solution {
    public int solution(int n, int[][] computers) {
        // 모든 점에 대해서, dfs + 방문체크를 해보면, 연결된 네트워크의 수를 알 수 있다.
        int cnt = 0;
        
        boolean[] visited = new boolean[n];
        
        for(int cur=0;cur<n;cur++){
            if(!visited[cur]){
                dfs(cur,computers,visited);
                cnt++;
            }
        }
        
        return cnt;
    }
    
    private void dfs(int current,int[][]computers, boolean[] visited){
        
        visited[current] = true; // 방문 처리
        
        // 현재 점과 이어져 있는 모든 점 확인
        for(int next=0; next<computers.length;next++){
            // 방문한 적 없고, 이어져 있으면(current -> next) 이동
            if(!visited[next] && computers[current][next] == 1){
                dfs(next,computers,visited);
            }
        }
        
        
    }
   
}