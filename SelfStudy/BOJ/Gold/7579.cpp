#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 101
#define MAX_COST_SUM 10001

int N, M, costSum;
int answer = MAX_COST_SUM;
vector<int> memory(MAX_N);
vector<int> cost(MAX_N);
vector<vector<int>> dp(MAX_N, vector<int>(MAX_COST_SUM));

int main() {
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++) {
        scanf("%d", &memory[i]);
    }

    for (int i=1; i<=N; i++) {
        scanf("%d", &cost[i]);
        costSum += cost[i];
    }

    // 배낭 문제 응용!
    // M 바이트를 확보하기 위한 앱 비활성화의 최소 비용 구하기
    // dp[i][j]: n개의 앱 중에서 i번째 앱까지 j만큼의 비용 비활성화할 때 확보 가능한 메모리
    for (int i=1; i<=N; i++) { // N의 최댓값: 100
        for (int j=0; j<=costSum; j++) { // costSum 최댓값: N * ci = 100 * 100 = 10,000
            if (cost[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);

            if (dp[i][j] >= M) answer = min(answer, j);
        }
    }

    printf("%d", answer);

    return 0;
}