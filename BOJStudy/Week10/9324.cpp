#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string message;
    vector<string> answers;
    for (int i=0; i<N; i++) {
        cin >> message;

        bool flag = true;
        unordered_map<char, int> counter;
        for (int j=0; j<message.size(); j++) {
            counter[message[j]]++;
            if (counter[message[j]] % 3 == 0) {
                if (j == message.size()-1 || message[j+1] != message[j]) {
                    answers.push_back("FAKE");
                    flag = false;
                    break;
                }
                else {
                    j++;
                }
            }
        }
        if (flag) {
            answers.push_back("OK");
        }
    }

    for (int i=0; i<N; i++) {
        cout << answers[i]  <<"\n";
    }

    return 0;
}