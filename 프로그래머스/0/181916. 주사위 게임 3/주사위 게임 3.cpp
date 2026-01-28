#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    int cnt[7] ={0,};
    cnt[a]++;cnt[b]++;cnt[c]++;cnt[d]++;
    vector<int>v;
    for(int i= 1;i<=6;i++){
        if(cnt[i])v.push_back(i);
    }
    
    // 4개가 같음
    if(v.size()==1){
        answer = 1111 * v[0];
    }
    // 3개가 같음
    if(v.size()==2){
        int p,q;
        
        if(cnt[v[0]]==3){
            p = v[0];
            q = v[1];
        }else if(cnt[v[1]]==3){
            p = v[1];
            q = v[0];
        }else {
            return (v[0]+v[1]) * abs(v[0]-v[1]);
        }
        
        answer = (10*p+q)*(10*p+q);
        
        
    }
    if(v.size()==3){
        if(cnt[v[0]]==2){
            answer = v[1] * v[2];
        }else if(cnt[v[1]]==2){
            answer = v[0] * v[2];
        }else if(cnt[v[2]]==2){
            answer = v[0] * v[1];
        }
    }
    
    if(v.size()==4)return *min(v.begin(),v.end());
    
    
    
    return answer;
}