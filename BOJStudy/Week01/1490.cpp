#include <iostream>
#include <string>
#include <queue>
using namespace std;

string N;
int len;

bool isValid(string s) {
    // N의 0이 아닌 모든 자리수로 나누어지는 떨어지는 수인지 체크
    long long number = stoll(s);
    for (int i=0; i<len; i++) {
        int digit = N[i] - '0';
        if (digit == 0) { continue; }
        if (number % digit != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    len = N.size();
    
    if (isValid(N)) {
        cout << N;
        return 0;
    }

    queue<string> q;
    for (int i=0; i<=9; i++) {
        q.push(N+to_string(i));
    }

    while (1) {
        string candidate = q.front();
        q.pop(); 

        if (isValid(candidate)) {
            cout << candidate;
            return 0;
        }

        for (int i=0; i<=9; i++) {
            q.push(candidate+to_string(i));
        }
    }

    return 0;
}