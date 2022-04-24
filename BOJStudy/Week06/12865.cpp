#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> things(101);
vector<vector<int>> dp(101, vector<int>(100001));

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int W, V;
    for (int i=1; i<=N; i++) {
        scanf("%d %d", &W, &V);
        things[i] = {W, V};
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (things[i].first <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-things[i].first] + things[i].second);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("%d", dp[N][K]);

    return 0;
}