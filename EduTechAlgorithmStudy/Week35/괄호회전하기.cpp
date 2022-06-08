#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.size();
    
    deque<char> dq;
    for (int i=0; i<len; i++) {
        dq.push_back(s[i]);
    }
    
    int rotate = 0;
    do {
        stack<char> st;
        bool isValid = true;
        for (auto iter=dq.begin(); iter!=dq.end(); iter++) {
            if (st.empty() && (*iter == ')' || *iter == ']' || *iter == '}')) {
                isValid = false;
                break;
            }

            if (*iter == ')') {
                if (st.top() != '(') {
                    isValid = false;
                    break;
                }
                st.pop();
            }

            else if (*iter == ']') {
                if (st.top() != '[') {
                    isValid = false;
                    break;
                }
                st.pop();
            }

            else if (*iter == '}') {
                if (st.top() != '{') {
                    isValid = false;
                    break;
                }
                st.pop();
            }

            else { // '(' or '[' or '{'
                st.push(*iter);
            }
        }
        if (st.empty() && isValid) { answer++; }
        
        dq.push_back(dq.front());
        dq.pop_front();
        rotate++;
    } while (rotate < len);
    
    return answer;
}

int main() {
    vector<string> s = {"[](){}", "}]()[{", "[)(]", "}}}"};

    for (int i=0; i<s.size(); i++) {
        printf("%d\n", solution(s[i]));
    }

    return 0;
}