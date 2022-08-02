#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isValid(string banned, string user) {
    if (banned.size() != user.size()) { return false; }
    for (int i=0; i<banned.size(); i++) {
        if (banned[i] == '*') { continue; }
        if (banned[i] != user[i]) { return false; }
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int N = user_id.size();
    int M = banned_id.size();
    
    // 모든 경우의 수를 저장하는 unordered_set
    unordered_set<string> answers;
    
    // 제재 아이디를 banned_id 개수 만큼 추출하기 위한 vector 생성
    vector<int> isSelected;
    for (int i=0; i<M; i++) { isSelected.push_back(1); }
    for (int i=0; i<N-M; i++) { isSelected.push_back(0); }
    
    // next_permutation 활용하기 위해 오름차순 정렬
    sort(user_id.begin(), user_id.end()); 
    
    // 순서를 고려하여 조합 구성하기
    do {
        vector<string> aCase;
        for (int i=0; i<N; i++) {
            if (isSelected[i] && isValid(banned_id[i], user_id[i])) {
                aCase.push_back(user_id[i]);
            }
        }
        if (aCase.size() == M) {
            // 중복이 없게 경우의 수를 저장할 수 있도록
            // i) 정렬
            sort(aCase.begin(), aCase.end());
            // ii) 이번 경우의 수에 해당하는 제재 아이디들을 하나의 문자열로 연결
            string temp = "";
            for (int i=0; i<M; i++) { temp += aCase[i]; }
            // iii) unordered_set에 저장
            answers.insert(temp);
        }
    } while (next_permutation(user_id.begin(), user_id.end()));

    return answers.size();
}

int main() {
    vector<vector<string>> user_id = {
        {"frodo", "fradi", "crodo", "abc123", "frodoc"},
        {"frodo", "fradi", "crodo", "abc123", "frodoc"},
        {"frodo", "fradi", "crodo", "abc123", "frodoc"}
    };
    vector<vector<string>> banned_id = {
        {"fr*d*", "abc1**"},
        {"*rodo", "*rodo", "******"},
        {"fr*d*", "*rodo", "******", "******"}
    };

    for (int i=0; i<user_id.size(); i++) {
        printf("%d\n", solution(user_id[i], banned_id[i]));
    }

    return 0;
}