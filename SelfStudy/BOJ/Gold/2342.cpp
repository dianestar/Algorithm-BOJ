#include <iostream>
#include <vector>

using namespace std;

int len;
vector<int> sequence;
vector<vector<int>> power(5, vector<int>(5)); // power[i][j]: 발판 i에서 발판 j로 움직이는 데 드는 힘
vector<vector<vector<int>>> dp(5, vector<vector<int>>(5, vector<int>(100000))); // dp[i][j][k]: k번째 단계에서 두 발이 i, j 발판에 있을 때 k번째 ~ 마지막 지시사항까지 수행하면 사용되는 최소의 힘

// 규칙에 따라 power 벡터 채우기
void calculatePower() {
    for (int i=0; i<=4; i++) {
        for (int j=0; j<=4; j++) {
            // 같은 지점 한번 더: 1의 힘 사용
            if (i == j) power[i][j] = 1;

            // 중앙 -> 다른 지점: 2의 힘 사용
            else if (i == 0) power[i][j] = 2;

            // 0은 수열의 마지막을 의미
            else if (j == 0) continue;

            // 중앙 외 다른 지점 -> 인접 지점: 3의 힘 사용
            else if (abs(i - j) != 2)  power[i][j] = 3;

            // 중앙 외 다른 지점 -> 반대편: 4의 힘 사용
            else power[i][j] = 4;
        }
    }
}

// dfs + dynamic programming (memoization)
int moveFoot(int footA, int footB, int nextIdx) {
    if (nextIdx == len) return 0;
    if (dp[footA][footB][nextIdx]) return dp[footA][footB][nextIdx];

    int nextVal = sequence[nextIdx];
    int moveFootA = power[footA][nextVal] + moveFoot(nextVal, footB, nextIdx + 1);
    int moveFootB = power[footB][nextVal] + moveFoot(footA, nextVal, nextIdx + 1);
    return dp[footA][footB][nextIdx] = min(moveFootA, moveFootB);
}

int main() {
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;
        sequence.push_back(num);
    }

    len = sequence.size();
    calculatePower();
    printf("%d", moveFoot(0, 0, 0));

    return 0;
}