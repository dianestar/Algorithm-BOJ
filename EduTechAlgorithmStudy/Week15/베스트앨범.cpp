#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp1(pair<string, int> a, pair<string, int> b) { // {장르, 장르 총 재생 횟수}
     //1. 속한 노래가 많이 재생된 장르를 먼저 수록
    return a.second > b.second;
}

bool cmp23(pair<int, int> a, pair<int,int> b) { // {고유 번호, 재생 횟수}
    //3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
    if (a.second == b.second) {
        return a.first < b.first;
    }
    
    //2. 장르 내에서 많이 재생된 노래를 먼저 수록
    else {
        return a.second > b.second;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> totalM; // {장르, 장르 총 재생 횟수}
    unordered_map<string, vector<pair<int, int>>> musicList; // {장르, {고유 번호, 재생 횟수}}
    for (int i=0; i<genres.size(); i++) {
        totalM[genres[i]] += plays[i];
        musicList[genres[i]].push_back({i, plays[i]});
    }
    vector<pair<string, int>> totalV(totalM.begin(), totalM.end()); 
    sort(totalV.begin(), totalV.end(), cmp1);
    
    for (auto iter=musicList.begin(); iter!=musicList.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), cmp23);
    }
    
    for (int i=0; i<totalV.size(); i++) {
        // cf) totalV[idx].first: 장르(musicList의 key로 활용)
        // cf) musicList[key][idx].first: 고유 번호
        answer.push_back(musicList[totalV[i].first][0].first);
        if (musicList[totalV[i].first].size() > 1) {
            answer.push_back(musicList[totalV[i].first][1].first);
        }
    }
    
    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};

    vector<int> v = solution(genres, plays);
    for(int i=0; i<v.size(); i++) {
        printf("%d ", v[i]);
    }
    
    return 0;
}