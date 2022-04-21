#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> dial;
    for (int i=2; i<=9; i++) {
        if (i == 7 || i == 9) {
            for (int j=0; j<4; j++) {
                dial.push_back(i);
            }
        }
        else {
            for (int j=0; j<3; j++) {
                dial.push_back(i);
            }
        }
    }

    string str;
    cin >> str;

    int answer = 0;
    for (int i=0; i<str.size(); i++) {
        answer += dial[str[i]-'A'] + 1;
    }

    cout << answer;

    return 0;
}