#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    // ai = a1, a2, a3, ... an 에서 i의 숫자가 작을수록 튜플을 표현하는 집합에서 여러 번 등장
    // 원소가 등장한 횟수가 많은 순으로 정렬
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string temp = "";
    unordered_map<int, int> um;
    for (int i=1; i<s.size()-1; i++) {
        if (s[i] == '{' || s[i] == ',' && s[i-1] == '}') { continue; }
        else if (s[i] == ',' && s[i-1] != '}' || s[i] == '}') {
            um[stoi(temp)]++; // 원소가 등장한 횟수 증가
            temp = "";
        }
        else {
            temp += s[i];
        }
    }
    
    // {key, value} 형태의 map을 value 기준으로 정렬하기 위해 vector로 변환
    vector<pair<int, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<v.size(); i++) {
        answer.push_back(v[i].first);
    }
        
    return answer;
}

int main() {
    vector<string> s = {"{{2},{2,1},{2,1,3},{2,1,3,4}}", "{{1,2,3},{2,1},{1,2,4,3},{2}}", "{{20,111},{111}}", "{{123}}", "{{4,2,3},{3},{2,3,4,1},{2,3}}"};
    
    for (int i=0; i<s.size(); i++) {
        vector<int> answer = solution(s[i]);
        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }
    
    return 0;
}