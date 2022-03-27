#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    vector<int> stairs;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        stairs.push_back(num);
    }

    if (N == 1) {
        printf("%d", stairs[0]);
    }
    else if (N == 2) {
        printf("%d", stairs[0] + stairs[1]);
    }
    else {
        vector<int> dp (N+1, 0);
        dp[0] = stairs[0];
        dp[1] = stairs[0] + stairs[1];
        dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

        for (int i=3; i<N; i++) {
            dp[i] = max(stairs[i] + dp[i-2], stairs[i] + stairs[i-1] + dp[i-3]);
        }
        printf("%d", dp[N-1]);
    }

    return 0;
}