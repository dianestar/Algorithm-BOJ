#include <iostream>
#include <algorithm>
using namespace std;

// 1. 몇 초가 흘렀는가
// 2. 몇 번 이동하였는가
// 3. 현재 인간 자두의 위치는 어디인가
int dp[1001][31][3];
int flags[1001];

int main() {
    int T, W;
    scanf("%d %d", &T, &W);

    for (int i=1; i<=T; i++) {
        scanf("%d", &flags[i]);
    }

    int move = 0;
    while (move <= W) {
        for (int t=1; t<=T; t++) {
            if (move == 0) {
                if (flags[t] == 1) {
                    dp[t][move][1] = dp[t-1][move][1] + 1;
                }
            }
            else {
                if (flags[t] == 1) {
                    dp[t][move][1] = max(dp[t-1][move-1][2] + 1, dp[t-1][move][1] + 1);
                    dp[t][move][2] = max(dp[t-1][move-1][1], dp[t-1][move][2]);
                }
                else {
                    dp[t][move][1] = max(dp[t-1][move-1][2], dp[t-1][move][1]);
                    dp[t][move][2] = max(dp[t-1][move-1][1] + 1, dp[t-1][move][2] + 1);
                }
            }
        }
        move++;
    }

    int answer = 0;
    for (int i=1; i<=2; i++) {
        for (int j=0; j<=W; j++) {
            answer = max(answer, dp[T][j][i]);
        }
    }

    printf("%d", answer);

    return 0;
}