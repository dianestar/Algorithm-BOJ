#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<string> validBoardA = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

vector<string> validBoardB = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> board;
    string oneLine;
    for (int i=0; i<N; i++) {
        cin >> oneLine;
        board.push_back(oneLine);
    }

    int minToColor = INT_MAX;
    for (int r=0; r<=N-8; r++) {
        for (int c=0; c<=M-8; c++) {
            int countA = 0;
            int countB = 0;
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (board[i+r][j+c] != validBoardA[i][j]) {
                        countA++;
                    }
                    if (board[i+r][j+c] != validBoardB[i][j]) {
                        countB++;
                    }
                }
            }
            minToColor = min(minToColor, min(countA, countB));
        }
    }

    cout << minToColor;

    return 0;
}