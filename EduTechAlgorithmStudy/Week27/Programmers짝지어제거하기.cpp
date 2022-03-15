#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int solution(string s) {
    int len = s.size();
    
    stack<char> st;
    st.push(s[0]);
    for (int i=1; i<len; i++) {
        if (!st.empty() && s[i] == st.top()) { st.pop(); }
        else { st.push(s[i]); }
    }
    
    if (st.empty()) { return 1; }
    else { return 0; }
}

int main() {
    vector<string> s = {"baabaa", "cdcd"};

    for (int i=0; i<s.size(); i++) {
        printf("%d\n", solution(s[i]));
    }

    return 0;
}