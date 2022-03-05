#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> map(101, vector<int>(101, 0));

bool isInvalid(int m, int n, int row, int col) {
    // 격자의 범위를 벗어나거나 물이 잠긴 지역을 가리키는 좌표일 경우 invalid
    if (row <= 0 || row > m || col <=0 || col > n || map[row][col] == -1) {
        return true;
    }
    return false;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (int i=0; i<puddles.size(); i++) {
        for (int j=0; j<puddles[i].size(); j++) {
            map[puddles[i][0]][puddles[i][1]] = -1; // 물이 잠긴 지역은 -1로 표시
        }
    }
    
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (map[i][j] == -1) { continue;} // 물이 잠긴 지역은 continue
            
            if (i == 1 && j == 1) { map[i][j] = 1; } // 집의 위치(시작 지점)은 1로 초기화
            
            // Dynamic Programming 활용
            // (1, 1)부터 (i, j)까지 이동할 수 있는 경로의 수 누적으로 저장
            // 현재 좌표로 왼쪽 또는 위쪽에서만 이동해올 수 있음
            if (!isInvalid(m, n, i-1, j)) { map[i][j] += map[i-1][j]; } 
            if (!isInvalid(m, n, i, j-1)) { map[i][j] += map[i][j-1]; }
            
            map[i][j] %= 1000000007;
        }
    }
    
    answer = map[m][n];
    
    return answer;
}

int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2,2}};

    printf("%d", solution(m, n, puddles));

    return 0;
}