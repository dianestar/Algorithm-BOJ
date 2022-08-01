#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=n; i++) {
        // i번 칸에 도달하는 방법 a) i-2번 칸에서 2칸 뛰기 or b) i-1번 칸에서 1칸 뛰기
        dp[i] = (dp[i-2] + dp[i-1]) % 1234567;
    }
    
    return dp[n];
}

int main() {
    vector<int> n = {4, 3};
    for (int i=0; i<n.size(); i++) {
        printf("%lld\n", solution(n[i]));
    }
    return 0;
}