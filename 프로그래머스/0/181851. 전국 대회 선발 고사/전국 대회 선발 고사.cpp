#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    for(int i=0;i<rank.size();i++){
        if(attendance[i])pq.push({rank[i],i});
    }
    
    int a = pq.top().second; 
    pq.pop();
    int b = pq.top().second;
    pq.pop();
    int c = pq.top().second;
    pq.pop();
    answer = 10000*a+100*b+c;
    
    return answer;
}