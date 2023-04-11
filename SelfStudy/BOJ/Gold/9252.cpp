#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LEN 1001
#define FROM_UPPER_LEFT 0
#define FROM_UP 1
#define FROM_LEFT 2

// dp[i][j].first: LCS의 길이
// dp[i][j].second: LCS 백트레킹을 위한 flag
vector<vector<pair<int, int>>> dp(MAX_LEN, vector<pair<int, int>>(MAX_LEN));
int maxLen, maxRow, maxCol;
string maxStr, strA, strB;

void findLCS() {
    int lenA = strA.size();
    int lenB = strB.size();
    strA = ' ' + strA;
    strB = ' ' + strB;

    for (int i=1; i<=lenA; i++) {
        for (int j=1; j<=lenB; j++) {
            if (strA[i] == strB[j]) {
                dp[i][j] = {dp[i-1][j-1].first + 1, FROM_UPPER_LEFT};
                if (dp[i][j].first > maxLen) {
                    maxLen = dp[i][j].first;
                    maxRow = i;
                    maxCol = j;
                }
            }
            else if (dp[i-1][j].first >= dp[i][j-1].first) {
                dp[i][j] = {dp[i-1][j].first, FROM_UP};
            }
            else {
                dp[i][j] = {dp[i][j-1].first, FROM_LEFT};
            }
        }
    }
}

void printLCS(int i, int j) {
    if (i == 0 || j == 0) return;

    if (dp[i][j].second == FROM_UPPER_LEFT) {
        printLCS(i-1, j-1);
        cout << strA[i];
    }
    else if (dp[i][j].second == FROM_UP) {
        printLCS(i-1, j);
    }
    else { // dp[i][j].second == FROM_LEFT
        printLCS(i, j-1);
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> strA >> strB;

    // LCS (Longest Common Subsequence, 최장 공통 부분 수열)
    findLCS();
    cout << maxLen << "\n";
    printLCS(maxRow, maxCol);

    return 0;
}