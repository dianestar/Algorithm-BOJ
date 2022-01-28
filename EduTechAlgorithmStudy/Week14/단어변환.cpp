#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int length = words[0].length(); //cf) 모든 단어의 길이는 같음
    vector<int> depth(words.size(), 0); //if visited, depth > 0
    queue<pair<int, string>> q; //depth와 word를 pair 형태로 담는 queue
    q.push({0, begin}); //begin 단어의 depth 값은 0
    
    while (!q.empty()) {
        int currDepth = q.front().first; 
        string currWord = q.front().second;
        
        if (currWord == target) {
            answer = currDepth;
            break;
        }
        
        q.pop();
        
        for (int i=0; i<words.size(); i++) {
            int match = 0;
            if (depth[i] == 0) {
                for (int j=0; j<length; j++) {
                    if (words[i][j] == currWord[j]) {
                        match++;
                    }
                }
                if (match == length-1) {
                    depth[i] = currDepth + 1;
                    q.push({depth[i], words[i]});
                }
            }
        }
    }
    
    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

    printf("%d", solution(begin, target, words));

    return 0;
}