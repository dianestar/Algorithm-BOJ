#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // a가 b를 이겼으면 isWinner[a][b]에 true 값 저장
    vector<vector<bool>> isWinner(n+1, vector<bool>(n+1, false));
    int size = results.size();
    for (int i=0; i<size; i++) {
        isWinner[results[i][0]][results[i][1]] = true;
    }
    
    // Floyd-Warshall Algorithm 활용
    // i가 k를 이기고 k가 j를 이긴 경우, isWinner[i][j]에도 true 값 저장
    for (int k=1; k<n+1; k++) {
        for (int i=1; i<n+1; i++) {
            for (int j=1; j<n+1; j++) {
                if (i == k) { continue; }
                if (isWinner[i][k] && isWinner[k][j]) {
                    isWinner[i][j] = true;
                }
            }
        }
    }
    
    // i가 j를 이긴 경우 또는 j가 i를 이긴 경우 cnt 값 증가
    // 자신을 제외한 n-1명과의 경기 결과를 알 수 있을 경우 순위 확정 가능
    for (int i=1; i<n+1; i++) {
        int cnt = 0;
        for (int j=1; j<n+1; j++) {
            if (isWinner[i][j] || isWinner[j][i]) { cnt++; }
        }
        if (cnt == n-1) { answer++; }
    }
    
    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = {{4,3}, {4,2}, {3,2}, {1,2}, {2,5}};

    printf("%d", solution(n, results));
    
    return 0;
}