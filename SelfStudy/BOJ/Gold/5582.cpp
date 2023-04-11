#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LEN 4001

vector<vector<int>> dp(MAX_LEN, vector<int>(MAX_LEN));
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strA, strB, lcs;
    cin >> strA >> strB;

    // 가장 긴 공통 부분 문자열 Longest Common Substring ⭕ Subsequence ❌ 의 길이 구하기
    int lenA = strA.size();
    int lenB = strB.size();
    for (int i=0; i<lenA; i++) {
        for (int j=0; j<lenB; j++) {
            if (strA[i] == strB[j]) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                
                if (dp[i][j] > answer) answer = dp[i][j];
            }
        }
    }

    cout << answer;

    return 0;
}