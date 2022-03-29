#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 학생들이 읽을 수 있는 단어 개수의 최댓값
int maxCount;

// cf) 남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 
vector<char> defaultList = {'a', 'n', 't', 'i', 'c'}; 

// 가르칠 후보 알파벳들을 중복 없이 담기 위한 set
unordered_set<char> candidatesSet; 

// key: 알파벳 아스키코드 - 'a' 값 (즉 key 0번은 'a'를 의미), value: 0일 경우 가르치지 않음 1일 경우 가르침
unordered_map<int, int> teachingMap; 

void addCandidates(string str) {
    int len = str.size();
    for (int i=0; i<len; i++) {
        // a, n, t, i, c 중 하나라면 continue
        if (find(defaultList.begin(), defaultList.end(), str[i]) != defaultList.end()) {
            continue;
        }
        // 그 외 알파벳이라면 candidatesSet에 insert
        candidatesSet.insert(str[i]);
    }
}

bool isReadAble(string str) {
    int len = str.size();
    for (int i=0; i<len; i++) {
        // 한 알파벳이라도 가르치지 않은 경우 읽을 수 없음
        if (teachingMap[str[i]-'a'] == 0) {
            return false;
        }
    }
    // 읽을 수 있음
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<string> strList;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;

        // prefix 'anta' 삭제
        for (int i=0; i<4; i++) { str.erase(0,1); }
        // postfix 'tica' 삭제
        for (int i=0; i<4; i++) { str.pop_back(); }
        
        strList.push_back(str);
        addCandidates(str);
    }

    
    // a, n, t, i, c 최소 5개의 글자는 알아야 어떤 단어든 읽을 수 있음
    if (K < 5) {
        cout << 0;
        return 0;
    }
    K -= 5;
    for (int i=0; i<5; i++) {
        teachingMap[defaultList[i]-'a'] = 1;
    }

    // set을 vector로 변환
    vector<int> candidates;
    candidates.assign(candidatesSet.begin(), candidatesSet.end());
    int candidatesSize = candidates.size();

    // next_permutation을 활용한 조합으로 가르칠 알파벳 선택
    vector<int> isSelected;
    for (int i=0; i<candidatesSize-K; i++) { isSelected.push_back(0); }
    for (int i=0; i<K; i++) { isSelected.push_back(1); }
    do {
        // 선택된 알파벳 key에 대해 teachingMap value 변경
        for (int i=0; i<candidatesSize; i++) {
            if (isSelected[i]) {
                teachingMap[candidates[i]-'a'] = 1;
            }
        }

        // 이번 경우 학생들이 읽을 수 있는 단어의 개수 카운트
        int curCount = 0;
        for (int i=0; i<N; i++) {
            if (strList[i].empty() || isReadAble(strList[i])) {
                curCount++;
            }
        }

        // maxCount 값 업데이트
        if (curCount > maxCount) {
            maxCount = curCount;
        }

        // teachingMap 백트래킹
        for (int i=0; i<candidatesSize; i++) {
            if (isSelected[i]) {
                teachingMap[candidates[i] - 'a'] = 0;
            }
        }
    } while (next_permutation(isSelected.begin(), isSelected.end()));

    cout << maxCount;
    return 0;
}