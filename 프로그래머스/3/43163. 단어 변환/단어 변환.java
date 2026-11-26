import java.util.Queue;
import java.util.ArrayDeque;

class Solution {  
    
    static class State{
        int count;
        String str;
        
        State(int count,String str){
            this.count = count;
            this.str = str;
        }
    }
    
    // 최단 경로니까, BFS로 풀어야 편할 듯
    public int solution(String begin, String target, String[] words) {
        
        // 큐 : {처리 횟수, 처리 중인 단어}
        // BFS 순회하면, 최단 경로 찾기 가능(방문 처리 해야함)
        
        boolean[] visited = new boolean[words.length];
        
        Queue<State> queue = new ArrayDeque<>();
        queue.offer(new State(0,begin));
        
        for(int i=0 ;i<words.length;i++){
            if(begin.equals(words[i])){
                visited[i] = true;
                break;
            }
        }
        
        while(!queue.isEmpty()){
            State current = queue.poll();
            int count = current.count;
            String cur = current.str;
            
            if(cur.equals(target)){
                return count;
            }
            
            for(int i=0;i<words.length;i++){
                if(!visited[i]&&canChange(cur,words[i])){
                    visited[i] = true;
                    queue.offer(new State(count+1,words[i]));
                }
            }
            
        }
        return 0;
    }
    
    private boolean canChange(String a, String b){
        
        int diff = 0;
        for(int i=0; i<a.length();i++){
            
            if(a.charAt(i) != b.charAt(i)){
                diff++;
            }
            
            if(diff >1){
                return false;
            }
            
        }
        return diff == 1;
    } 
    
}