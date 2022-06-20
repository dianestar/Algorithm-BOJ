#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> arr) {
    map<int, int> countingMap;
    for (int i=0; i<arr.size(); i++) {
        countingMap[arr[i]]++;
    }

    vector<int> answers;
    for (auto iter=countingMap.begin(); iter!=countingMap.end(); iter++) {
        if (iter->second == 1) { continue; }
        else {
            answers.push_back(iter->second);
        }
    }

    if (answers.size() == 0) {
        answers.push_back(-1);
    }
    return answers;
}

int main() {
    vector<vector<int>> arr = {
        {1,2,3,3,3,3,4,4},
        {3,2,4,4,2,5,2,5,5}
    };

    for (int i=0; i<arr.size(); i++) {
        vector<int> answers = solution(arr[i]);
        for (int j=0; j<answers.size(); j++) {
            printf("%d ", answers[j]);
        }
        printf("\n");
    }

    return 0;
}