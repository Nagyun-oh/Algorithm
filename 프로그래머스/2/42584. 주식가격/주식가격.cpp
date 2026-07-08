#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len);
    
    // 끝까지 가격이 떨어지지 않았다고 가정한 초기값
    for(int i=0;i<len;i++){
        answer[i] = len - (i+1);
    }

    stack<int> st;  // 아직 가격이 떨어지지 않은 인덱스
    
    for(int i=0;i<len;i++){
        // 현재 가격 때문에 이전 가격이 처음으로 떨어졌다면
        while(!st.empty()&& prices[st.top()] > prices[i]){
            int previousIndex = st.top();
            st.pop();
            
            answer[previousIndex] = i-previousIndex;
        }
        
        st.push(i);
    }
    
    return answer;
}