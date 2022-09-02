#include <iostream>
#include <vector>
using namespace std;

struct Fish {
    int dir, row, col, isDead;
};

// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int answer = 0;

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= 4 || col < 0 || col >=4) {
        return true;
    }
    return false;
}

void moveFishes(vector<vector<int>> &matrix, vector<Fish> &fishes, int sharkRow, int sharkCol) {
    for (int i=1; i<=16; i++) { // 1번~16번 물고기 순서대로 이동
        // 상어에게 먹힌 물고기의 경우 스킵
        if (fishes[i].isDead == 1) { continue; }
        
        int nextRow = fishes[i].row + dr[fishes[i].dir];
        int nextCol = fishes[i].col + dc[fishes[i].dir];

        for (int j=0; j<8; j++) {
            // 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸
            if (isOutOfRange(nextRow, nextCol) || (nextRow == sharkRow && nextCol == sharkCol)) {
                fishes[i].dir = (fishes[i].dir + 1) % 8;
                nextRow = fishes[i].row + dr[fishes[i].dir];
                nextCol = fishes[i].col + dc[fishes[i].dir];
            }
            else {
                break;
            }
        }

        // 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸
        if (matrix[nextRow][nextCol] == -1) { // 빈 칸일 경우
            matrix[nextRow][nextCol] = i;
            matrix[fishes[i].row][fishes[i].col] = -1;

            fishes[i].row = nextRow;
            fishes[i].col = nextCol;
        }
        else { // 다른 물고기가 있는 칸일 경우
            int exchangeFish = matrix[nextRow][nextCol];
            matrix[nextRow][nextCol] = i;
            matrix[fishes[i].row][fishes[i].col] = exchangeFish;

            fishes[exchangeFish].row = fishes[i].row;
            fishes[exchangeFish].col = fishes[i].col;
            fishes[i].row = nextRow;
            fishes[i].col = nextCol;
        }
    }
}

void solution(vector<vector<int>> tempMatrix, vector<Fish> tempFishes, int row, int col, int sum) {
    // 상어가 물고기를 먹음
    int targetFish = tempMatrix[row][col];
    int sharkDir = tempFishes[targetFish].dir;
    tempFishes[targetFish].isDead = 1;
    tempMatrix[row][col] = -1;
    sum += targetFish;

    // 합이 최댓값일 경우 갱신
    if (sum > answer) { answer = sum; }

    // 물고기 이동
    moveFishes(tempMatrix, tempFishes, row, col);

    // 상어 이동
    int nextRow, nextCol;
    for (int i=1; i<=3; i++) { // 4*4 행렬 구조이므로 최대 3칸까지 이동 가능
        nextRow = row + dr[sharkDir] * i;
        nextCol = col + dc[sharkDir] * i;

        // 공간의 경계를 넘는 칸으로는 이동할 수 없음
        if (isOutOfRange(nextRow, nextCol)) { break; }

        //  물고기가 없는 칸으로는 이동할 수 없으나 지나갈 수는 있음
        if (tempMatrix[nextRow][nextCol] == -1) { continue; }

        // 재귀적으로 호출
        solution(tempMatrix, tempFishes, nextRow, nextCol, sum);
    }
}

int main() {
    vector<vector<int>> matrix(4, vector<int>(4));
    vector<Fish> fishes(17);

    int a, b;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d %d", &a, &b);
            matrix[i][j] = a;
            fishes[a] = {b-1, i, j, 0};
        }
    }

    solution(matrix, fishes, 0, 0, 0);
    printf("%d", answer);

    return 0;    
}
