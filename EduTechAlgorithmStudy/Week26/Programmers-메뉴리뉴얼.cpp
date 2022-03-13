#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

void getCombination(string order, int count) {
    // next_permutation을 활용한 조합 구하기
    vector<int> selected;
    for (int i=0; i<order.size()-count; i++) { selected.push_back(0); }
    for (int i=0; i<count; i++) { selected.push_back(1); }
    
    do {
        string key = "";
        for (int i=0; i<selected.size(); i++) {
            if (selected[i]) { key += order[i]; }
        }

        // cf) 배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬
        sort(key.begin(), key.end()); 
        m[key]++;
    } while (next_permutation(selected.begin(), selected.end()));
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i=0; i<orders.size(); i++) {
        for (int j=0; j<course.size(); j++) {
            if (orders[i].size() >= course[j]) {
                getCombination(orders[i], course[j]);
            }
        }
    }

    // 주문된 횟수가 많은 순으로 단품메뉴 조합 정렬
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp); 

    for (int i=0; i<course.size(); i++) {
        int maxCount = 2;
        for (auto iter=v.begin(); iter!=v.end(); iter++) {
            if (iter->first.size() == course[i] && iter->second >= maxCount) {
                maxCount = iter->second;
                answer.push_back(iter->first);
            }
        }
    }

    // cf) 정답은 각 코스요리 메뉴의 구성을 문자열 형식으로 배열에 담아 사전 순으로 오름차순 정렬
    sort(answer.begin(), answer.end()); 

    return answer;
}

int main() {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};

    vector<string> answer = solution(orders, course);
    for (int i=0; i<answer.size(); i++) {
        printf("%s ", answer[i].c_str());
    }

    return 0;
}