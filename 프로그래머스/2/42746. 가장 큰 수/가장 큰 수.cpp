#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a,string b){
    string s1 = a+b;
    string s2 = b+a;
    
    return s1 > s2;

}
string solution(vector<int> numbers) {
    string answer = "";
    
    /*
    문제 정리:
        - 주어진 numbers배열의 원소는 0이상 1000이하의 정수
        - 정수를 이어 붙여 만들 수 있는 가장 큰 수 구하기
        - numbers의 길이는 최대 100,000이므로, 2중 for문 x
        - 예시에서는 배열 목록을 만든 다음에 가장 큰 수를 구함
        - 정답이 너무 클 수 있으니 문자열을 return
    
    설계:
        1. numbers를 string 배열로 변환한다.
        2. 두 문자열 a,b에 대해 a+b > b+a 기준으로 정렬한다.
        3. 정렬된 문자열을 전부 이어 붙인다.
    */
    
    vector<string> nums;
    for(int num: numbers){
        nums.push_back(to_string(num));
    }
    
    sort(nums.begin(),nums.end(),cmp);
    
    for(string num : nums){
        answer+=num;
    }
    
    if(nums[0]=="0") return "0";
    
    return answer;
}