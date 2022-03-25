#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int price;
    vector<int> prices(N+1);
    for (int i=1; i<=N; i++) {
        scanf("%d", &price);
        prices[i] = price;
    }

    vector<int> dp(N+1, 0);
    dp[1] = prices[1];
    for (int i=2; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            dp[i] = max(dp[i], dp[i-j] + prices[j]);
        }
    }

    printf("%d", dp[N]);

    return 0;
}