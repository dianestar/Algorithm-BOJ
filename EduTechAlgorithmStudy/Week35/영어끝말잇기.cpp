#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string, bool> said;
    said[words[0]] = true;
    for (int i=1; i<words.size(); i++) {
        if (said[words[i]] || words[i][0] != words[i-1][words[i-1].size()-1]) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        said[words[i]] = true;      
    }
    
    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {
    vector<int> n = {3, 5, 2};
    vector<vector<string>> words = {
        {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"},
        {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"},
        {"hello", "one", "even", "never", "now", "world", "draw"}
    };

    for (int i=0; i<n.size(); i++) {
        vector<int> answer = solution(n[i], words[i]);
        printf("%d %d\n", answer[0], answer[1]);
    }

    return 0;
}