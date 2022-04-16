#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    vector<int> answers;
    for (int i=0; i<T; i++) {
        int K;
        scanf("%d", &K);

        vector<int> files(K+1);
        vector<int> sum(K+1, 0);
        for (int j=1; j<=K; j++) {
            scanf("%d", &files[j]); 
            sum[j] = sum[j-1] + files[j];
        }

        vector<vector<int>> dp(K+1, vector<int>(K+1, 0));
        for (int j=1; j<K; j++) { // 범위의 길이
            for (int k=1; k<=K-j; k++) { // 범위의 시작 지점
                dp[k][k+j] = INT_MAX;
                for (int l=k; l<k+j; l++) { // 범위를 두 부분으로 나누는 중간 지점
                    dp[k][k+j] = min(dp[k][k+j], dp[k][l] + dp[l+1][k+j] + sum[k+j] - sum[k-1]);
                }
            }
        }
        
        answers.push_back(dp[1][K]);
    }

    for (int i=0; i<T; i++) {
        printf("%d\n", answers[i]);
    }

    return 0;
}