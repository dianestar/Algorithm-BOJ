#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) { 
    int row = relation.size();
    int col = relation[0].size();

    // determined[i]: 결정된 후보 키를 구성하는 컬럼 인덱스를 이어붙인 string을 담는 벡터
    // ex. 컬럼 0번과 1번으로 후보 키를 구성한 경우 -> "01"이 담김
    vector<string> determined; 

    // 후보 키를 만들기 위해 하나의 컬럼을 선택하는 경우부터 모든 컬럼을 선택하는 경우까지 브루트포스
    // next_permutation을 활용한 조합 활용
    for (int i=1; i<=col; i++) {
        vector<int> isSelected;
        for (int j=0; j<col-i; j++) { isSelected.push_back(0); }
        for (int j=0; j<i; j++) { isSelected.push_back(1); }
        
        
        do {
            // 유일성(Uniqueness) 체크
            unordered_map<string, int> keyMap;
            bool isUnique = true;
            for (int j=0; j<row; j++) {
                string key = "";
                for (int k=0; k<col; k++) {
                    if (isSelected[k]) {
                        key += relation[j][k];
                    }
                }

                if (keyMap[key]) {
                    isUnique = false;
                    break;
                }
                else {
                    keyMap[key] = 1;
                }  
            }
            
            if (isUnique) {
                // 최소성(Minimality) 체크
                bool isMinimal = true;
                string key = "";
                for (int k=0; k<col; k++) {
                    if (isSelected[k]) {
                        key += to_string(k);
                    }
                }

                if (i == 1 || determined.size() == 0) {
                    determined.push_back(key);
                }
                else {
                    for (int k=0; k<determined.size(); k++) {
                        int count = 0;
                        for (int l=0; l<determined[k].size(); l++) {
                            if (key.find(determined[k][l]) != string::npos) {
                                count++;
                            }
                        }
                        if (count == determined[k].size()) {
                            isMinimal = false;
                            break;
                        }
                    }

                    if (isMinimal) {
                        determined.push_back(key);
                    }
                }
            }
        } while (next_permutation(isSelected.begin(), isSelected.end()));
    }

    return determined.size();
}

int main() {
    vector<vector<string>> relation = {
        /*
        {"100","ryan","music","2"},
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2"},
        */
        {"a", "a"},
        {"b", "b"}
    };

    printf("%d\n", solution(relation));

    return 0;
}