#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX_GEMS_LEN 100000

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    unordered_set<string> allTypes(gems.begin(), gems.end());
    int allCount = allTypes.size();
    
    // 투포인터 활용
    int start = 0;
    int end = 0;
    int curCount = 0;
    int len = MAX_GEMS_LEN;
    
    unordered_map<string, int> gemsMap;
    gemsMap[gems[0]]++;
    curCount++;

    while (1) {
        if (curCount == allCount) {
            if (end - start + 1 < len) {
                len = end - start + 1;
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            
            gemsMap[gems[start]]--;
            if (gemsMap[gems[start]] == 0) { curCount--; }
            start++;
        }
        
        if (curCount < allCount) {
            if (end == gems.size() - 1) { break; }
            
            end++;
            gemsMap[gems[end]]++;
            if (gemsMap[gems[end]] == 1) { curCount++; }
        }
    }    

    return answer;
}

/* 슬라이딩 윈도우 활용 (시간초과)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    unordered_set<string> allTypes;
    for (int i=0; i<gems.size(); i++) {
        allTypes.insert(gems[i]);
    }

    int count = allTypes.size();
    while (1) {
        for (int i=0; i<=gems.size()-count; i++) {
            unordered_set<string> curTypes;
            for (int j=i; j<i+count; j++) {
                curTypes.insert(gems[j]);
            }

            if (curTypes.size() == allTypes.size()) {
                answer.push_back(i+1);
                answer.push_back(i+count);
                return answer;
            }
        }
        
        count++;
    }
}
*/

int main() {
    vector<vector<string>> gems = {
        {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"},
        {"AA", "AB", "AC", "AA", "AC"},
        {"XYZ", "XYZ", "XYZ"},
        {"ZZZ", "YYY", "NNNN", "YYY", "BBB"},
        {"A", "A", "B"}
    };

    for (int i=0; i<gems.size(); i++) {
        vector<int> answer = solution(gems[i]);
        printf("%d %d\n", answer[0], answer[1]);
    }
    
    return 0;
}