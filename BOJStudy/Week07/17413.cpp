#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

void printStack() {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    getline(cin, S);

    int len = S.size();
    for (int i=0; i<len; i++) {
        if (S[i] == '<') {
            printStack();
            while (S[i] != '>') {
                cout << S[i];
                i++;
            }
            cout << S[i];
        }

        else if (S[i] == ' ') {
            printStack();
            cout << ' ';
        }

        else {
            st.push(S[i]);
        }
    }
    printStack();

    return 0;
}