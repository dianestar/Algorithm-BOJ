#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int x, int y, int n) {
    // dp[x]: y를 x로 변환하기 위해 필요한 최소 연산 횟수
    vector<int> dp(y+1, INT_MAX);
    dp[y] = 0;
    
    queue<pair<int, int>> q;
    q.push({y, 0});
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        vector<double> candidates(3);
        candidates[0] = curr.first - n;
        candidates[1] = (double)curr.first / 2;
        candidates[2] = (double)curr.first / 3;
        
        for (int i=0; i<3; i++) {
            if (candidates[i] > 0 && (int)candidates[i] == candidates[i] && curr.second + 1 < dp[candidates[i]]) {
                dp[candidates[i]] = curr.second + 1;
                q.push({candidates[i], curr.second + 1});
            }
        }
    }
    
    return dp[x] == INT_MAX ? -1 : dp[x];
}

int main() {
    vector<vector<int>> input = {
        {10, 40, 5},
        {10, 40, 30},
        {2, 5, 4},
    };

    for (int i=0; i<input.size(); i++) {
        printf("%d\n", solution(input[i][0], input[i][1], input[i][2]));
    }

    return 0;
}