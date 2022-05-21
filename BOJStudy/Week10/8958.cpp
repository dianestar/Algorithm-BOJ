#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getScore(string result) {
    int totalScore = 0;
    int tempScore = 0;
    for (int i=0; i<result.size(); i++) {
        if (result[i] == 'X') {
            tempScore = 0;
        }
        else {
            tempScore++;
            totalScore += tempScore;
        }
    }
    return totalScore;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string result;
    vector<int> scores;
    for (int i=0; i<N; i++) {
        cin >> result;
        scores.push_back(getScore(result));
    }

    for (int i=0; i<N; i++) {
        cout << scores[i] << "\n";
    }

    return 0;
}