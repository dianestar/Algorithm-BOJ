#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1001
vector<int> cards(MAX_N);
vector<vector<int>> dp(MAX_N, vector<int>(MAX_N));

int selectCard(int i, int j, int flag) {
    if (i > j) return 0;
    if (dp[i][j]) return dp[i][j];

    if (flag) { // 근우 차례
        int frontFirst = cards[i] + selectCard(i+1, j, 0);
        int rearFirst = cards[j] + selectCard(i, j-1, 0);

        return dp[i][j] = max(frontFirst, rearFirst);
    }
    else { // 명우 차례
        int frontFirst = selectCard(i+1, j, 1);
        int rearFirst = selectCard(i, j-1, 1);

        return dp[i][j] = min(frontFirst, rearFirst);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T) {
        int N;
        scanf("%d", &N);

        for (int i=0; i<N; i++) {
            scanf("%d", &cards[i]);
        }

        // initialization 
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dp[i][j] = 0;
            }
        }
        
        // dynamic programming + recursion
        printf("%d\n", selectCard(0, N-1, 1));

        T--;
    }

    return 0;
}