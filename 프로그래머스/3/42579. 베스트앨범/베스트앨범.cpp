#include <string>
#include <vector>
#include <unordered_map> 
#include <algorithm>
using namespace std;

// Problem: 베스트 앨범에 들어갈 노래의 고유 번호를 장르별 2개씩 순서대로 반환
// Solve
    // 1)  장르별 재생 횟수에 대해서 1차적으로 필터링을 한다.
    // 2)  노래별 재생 횟수에 대해서 2차적으로 필터링을 한다.
    // 3)  장르 내에서 노래별 고유 번호가 낮은 순으로 마지막 필터링을 하여 구한다.

unordered_map<string,int> hashGenre; // 장르별 재생횟수에 대한 해시맵
unordered_map<string,vector<pair<int,int>>> hashSongs; // 장르별 노래의 (고유변호, 재생횟수)

bool cmp1(const string&a ,const string&b){
    return hashGenre[a] > hashGenre[b];
}

bool cmp2(const pair<int,int>&a ,const pair<int,int>&b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {    

    hashGenre.clear();
    hashSongs.clear();
    
    for(int i=0;i< genres.size();i++){
        hashGenre[genres[i]] += plays[i];
        
        // (재생횟수, 고유번호)
        hashSongs[genres[i]].push_back({plays[i],i});
    }
    
    // 장르 이름 목록 생성
    vector<string> genreOrder;
    
    for(const auto& entry : hashGenre){
        genreOrder.push_back(entry.first);
    }
    
    // 1) 장르별 전체 재생 횟수가 많은 장르부터 정렬
    sort(genreOrder.begin(),genreOrder.end(), cmp1 );
    
    vector<int> answer; 
    
    // 2~3) 재생횟수, 고유번호 별로 정렬
    for(const string& genre : genreOrder){
        vector<pair<int,int>>& songs = hashSongs[genre];
        
        // 재생횟수 내림차순, 같으면 고유 번호 오름차순
        sort(songs.begin(),songs.end(),cmp2);
        
        // 장르별 최대 2곡 수록
        answer.push_back(songs[0].second);
        
        if(songs.size() >=2){
            answer.push_back(songs[1].second);
        }
    }
    return answer;
}