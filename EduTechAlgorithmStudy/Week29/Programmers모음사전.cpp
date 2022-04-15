#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
vector<string> dict;

void search(string temp, int count, int len) {
    if (count == len) {
        dict.push_back(temp);
        return;
    }
    
    for (int i=0; i<=4; i++) {
        temp += alphabet[i];
        search(temp, count+1, len);
        temp.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int i=1; i<=5; i++) {
        search("", 0, i);
    }
    
    sort(dict.begin(), dict.end());
    int dictSize = dict.size();
    for (int i=0; i<dictSize; i++) {
        if (word == dict[i]) {
            answer = i+1;
        }
    }

    return answer;
}

int main() {
    vector<string> word = {"AAAAE", "AAAE", "I", "EIO"};
    for (int i=0; i<word.size(); i++) {
        dict.clear();
        printf("%d\n", solution(word[i]));
    }
}