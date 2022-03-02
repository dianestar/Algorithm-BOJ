#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int powerN = pow(2,6); // cf) 2 <= N <= 6
int iceSum; // 남아있는 얼음 A[r][c]의 합
int maxCount; // 가장 큰 덩어리가 차지하는 칸의 개수
vector<vector<int>> tempGrid(powerN, vector<int>(powerN));
vector<vector<bool>> visited(powerN, vector<bool>(powerN));

int N, Q;
vector<vector<int>> grid(powerN, vector<int>(powerN)); // 2^N * 2^N 격자 얼음판
vector<int> L(1000); // 마법사 상어가 시전한 단계

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

/* 파이어스톰 시전 */
void rotateGrid(int row, int col, int powerL) { // 부분 격자 회전
    /*
    이전 단계의 '행'이 이번 단계의 '열'이 되는 원리
    1  2  3  4     13 9  5 1
    5  6  7  8     14 10 6 2
    9  10 11 12    15 11 7 3 
    13 14 15 16    16 12 8 4
    */
    for (int i=row, n=col; i<row+powerL; i++, n++) {
        for (int j=col, m=row+powerL-1; j<col+powerL; j++, m--) {
            grid[i][j] = tempGrid[m][n];
        }
    }
}

void divideGrid(int powerL) { // 부분 격자로 나누기
    // tempGrid에 이전 단계의 grid 저장
    copy(grid.begin(), grid.end(), tempGrid.begin());

    int row = 0; 
    int col = 0;
    while (row < powerN) {
        // (0,0)이 포함된 부분 격자부터 회전
        rotateGrid(row, col, powerL);

        // 다음 부분 격자의 시작 인덱스 찾기
        col += powerL; 
        if (col >= powerN) {
            col = 0;
            row += powerL;
        }
    }
}

bool outOfRange(int row, int col) {
    if (row < 0 || row >= powerN || col < 0 || col >= powerN) { return true; }
    return false;
}

void decreaseIce() {
    // tempGrid에 회전을 마친 grid 저장
    copy(grid.begin(), grid.end(), tempGrid.begin());

    for (int i=0; i<powerN; i++) {
        for (int j=0; j<powerN; j++) {
            if (tempGrid[i][j] == 0) {
                continue;
            }

            int count = 0; // 얼음이 있는 인접한 칸의 개수
            for (int k=0; k<4; k++) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (!outOfRange(nr, nc) && tempGrid[nr][nc] != 0) {
                    count++;
                }
            }

            // 얼음이 있는 칸 3개 이상과 인접하지 않은 칸의 얼음의 양 1 감소
            if (count < 3) {
                grid[i][j]--;
                iceSum--;
            }
        }
    }
}

/* 덩어리 탐색 */
int dfs(int row, int col, int curCount) {
    // curCount는 덩어리가 차지하는 칸의 개수
    visited[row][col] = true;
    curCount++; 
    for (int k=0; k<4; k++) {
        int nr = row + dr[k];
        int nc = col + dc[k];
        if (!outOfRange(nr, nc) && grid[nr][nc]!= 0 && !visited[nr][nc]) {
            curCount = dfs(nr, nc, curCount);
        }
    }
    return curCount;
}

void searchIceberg() {
    for (int i=0; i<powerN; i++) {
        for (int j=0; j<powerN; j++) {
            if (grid[i][j] != 0 && !visited[i][j]) {
                int count = dfs(i, j, 0);
                if (count > maxCount) {
                    maxCount = count;
                }
            }
        }
    }
}

int main() {
    // 입력
    scanf("%d %d", &N, &Q);
    powerN = pow(2, N);

    int num;
    for (int i=0; i<powerN; i++) {
        for (int j=0; j<powerN; j++) {
            scanf("%d", &num);
            grid[i][j] = num;
            if (num != 0) { iceSum += num; }
        }
    }

    for (int i=0; i<Q; i++) {
        scanf("%d", &L[i]);
    }

    // 파이어스톰 시전
    for (int i=0; i<Q; i++) {
        divideGrid(pow(2, L[i]));
        decreaseIce();
    }

    // 덩어리 탐색
    searchIceberg();

    // 출력
    printf("%d\n%d", iceSum, maxCount);

    return 0;
}