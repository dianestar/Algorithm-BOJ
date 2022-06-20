#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    int len = s.size();
    for (int i=1; i<len; i++) {
        string zip = "";
        string prev = s.substr(0, i);
        int count = 1;
        for (int j=i; j<len; j+=i) {
            string curr = s.substr(j, i);
            if (curr == prev) { count++; }
            else {
                if (count > 1) { zip += to_string(count); }
                zip += prev;
                prev = curr;
                count = 1;
            }
        }
        if (count > 1) { zip += to_string(count); }
        zip += prev;
        
        if (zip.size() < answer) { answer = zip.size(); }
    }
    
    return answer;
}

int main() {
    vector<string> s = {"aabbaccc", "ababcdcdababcdcd", "abcabcdede", "abcabcabcabcdededededede", "xababcdcdababcdcd"};
    for (int i=0; i<s.size(); i++) {
        cout << solution(s[i]) << "\n";
    }
    return 0;
}