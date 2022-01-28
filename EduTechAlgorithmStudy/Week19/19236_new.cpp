#include <iostream>
using namespace std;

struct Fish {
    int dir, row, col, isDead;
};

int answer = 0;

//0:UP 1:LEFT_UP 2:LEFT 3:LEFT_DOWN 4:DOWN RIGHT_DOWN:5 RIGHT:6 RIGHT_UP:7
int moveRow[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int moveCol[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

/*
void printFishes(int matrix[][4]) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

void moveFishes(int matrix[][4], Fish fishes[], int sharkRow, int sharkCol) {
    // cf) 물고기는 번호가 작은 물고기부터 순서대로 이동한다. 
    for (int i=1; i<=16; i++) { // 1번~16번 물고기 순서대로 이동
        // 상어에게 먹힌 물고기의 경우 스킵
        if (fishes[i].isDead == 1) { continue; }
        
        // 이동할 칸의 행열 값 구하여 이동 가능 여부 체크
        int nextRow = fishes[i].row + moveRow[fishes[i].dir];
        int nextCol = fishes[i].col + moveCol[fishes[i].dir];
        // cf) 물고기가 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.
        // cf) 각 물고기는 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다. 
        while (nextRow < 0 || nextRow >= 4 || nextCol < 0 || nextCol >= 4 ||
        nextRow == sharkRow && nextCol == sharkCol) {
            fishes[i].dir = (fishes[i].dir + 1) % 8;
            nextRow = fishes[i].row + moveRow[fishes[i].dir];
            nextCol = fishes[i].col + moveCol[fishes[i].dir];
        }

        // cf) 물고기가 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸이다.
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

void sharkSearch(int matrix[][4], Fish fishes[], int row, int col, int sum) {
    // 백트래킹을 위해 배열 복사
    int tempMatrix[4][4];
    Fish tempFishes[17];
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            tempMatrix[i][j] = matrix[i][j];
        }
    }
    for (int i=1; i<=16; i++) {
        tempFishes[i] = fishes[i];
    }

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
    // cf) 상어는 방향에 있는 칸으로 이동할 수 있는데, 한 번에 여러 개의 칸을 이동할 수 있다. 
    int nextRow, nextCol;
    for (int i=1; i<=3; i++) { // 4*4 행렬 구조이므로 최대 3칸까지 이동 가능
        nextRow = row + moveRow[sharkDir] * i;
        nextCol = col + moveCol[sharkDir] * i;

        // 공간의 경계를 넘는 칸으로는 이동할 수 없음
        if (nextRow < 0 || nextRow >= 4 || nextCol < 0 || nextCol >= 4) { break; }

        // cf) 물고기가 없는 칸으로는 이동할 수 없다.
        // 지나갈 수는 있음 주의!
        if (tempMatrix[nextRow][nextCol] == -1) { continue; }

        // 재귀적으로 호출
        sharkSearch(tempMatrix, tempFishes, nextRow, nextCol, sum);
    }
}

int main() {
    int matrix[4][4];
    Fish fishes[17];

    int a, b;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d %d", &a, &b);
            matrix[i][j] = a;
            fishes[a].dir = b-1;
            fishes[a].row = i;
            fishes[a].col = j;
            fishes[a].isDead = 0;
        }
    }

    sharkSearch(matrix, fishes, 0, 0, 0);
    printf("%d", answer);

    return 0;    
}