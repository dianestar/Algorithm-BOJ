#include <iostream>
#include <vector>
using namespace std;

vector<int> count(53, 0);

int encode(char c) {
    // 띄어쓰기 -> 0
    if (c == ' ') { return 0; }
    
    // A: 65 -> 1
    else if (c >= 'A' && c <= 'Z') { return c - 64; }

    // a: 97 -> 27
    else { return c - 70; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int num;
    for (int i=0; i<N; i++) {
        cin >> num;
        count[num]++;
    }

    string plaintext, newline;
    getline(cin, newline);
    getline(cin, plaintext);
    
    for (int i=0; i<plaintext.size(); i++) {
        if (count[encode(plaintext[i])] == 0) {
            printf("n");
            return 0;
        }
        count[encode(plaintext[i])]--;
    }
    printf("y");
    return 0;
}