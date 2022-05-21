#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    string answer = "";
    int bombLen = bomb.size();
    for (int i=0; i<str.size(); i++) {
        answer.push_back(str[i]);

        int answerLen = answer.size();
        if (answer[answerLen-1] == bomb[bombLen-1] && answerLen >= bombLen) {
            bool flag = true;
            for (int j=0; j<bombLen; j++) {
                if (bomb[j] != answer[answerLen-bombLen+j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                for (int j=0; j<bombLen; j++) {
                    answer.pop_back();
                }
            }
        }
    }

    if (answer.size() == 0) {
        answer = "FRULA";
    }

    cout << answer;
    return 0;
}