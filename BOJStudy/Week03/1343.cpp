#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string X;
    cin >> X;

    vector<int> v;
    int len = X.size();
    int count = 0;
    for (int i=0; i<len; i++) {
        if (X[i] == '.') {
            if (count > 0) {
                v.push_back(count);
                count = 0;
            }
            v.push_back(-1);
        }
        else {
            count++;
        }
    }
    if (count > 0) {
        v.push_back(count);
    }

    string answer = "";
    for (int i=0; i<v.size(); i++) {
        int value = v[i];
        if (value == -1) {
            answer += '.';
            continue;
        }

        for (int j=0; j<value/4; j++) {
            answer += "AAAA";
        }
        int remainder = value % 4;
        if (remainder % 2 == 0) {
            for (int j=0; j<remainder/2; j++) {
                answer += "BB";
            }
        }
        else {
            answer = "-1";
            break;
        }
    }

    cout << answer;

    return 0;
}