#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int N = triangle.size();
    vector<vector<int>> dp(N, vector<int>(N));
    dp[0][0] = triangle[0][0];
    
    for (int i=1; i<N; i++) {
        for (int j=0; j<i+1; j++) {
            if (j == 0) {
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }
            else if (j == i) {
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }
            else {
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    answer = *max_element(dp[N-1].begin(), dp[N-1].end());    
    
    return answer;
}

int main() {
    vector<vector<int>> triangle = {{7}, {3,8}, {8,1,0}, {2,7,4,4}, {4,5,2,6,5}};
    
    printf("%d", solution(triangle));

    return 0;
}
