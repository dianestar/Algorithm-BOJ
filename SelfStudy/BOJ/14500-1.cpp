// solution #1
#include <iostream>
#include <vector>
using namespace std;

// 오른쪽 아래쪽 왼쪽 위쪽
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int N, M;
int board[500][500];
int visited[500][500];
int maxValue = 0;

/*
void printBoard(vector<vector<int>> board) {
    cout << endl;
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/

// T자 모양을 제외한 나머지 네 가지 모양
void searchRest(int row, int col, int depth, int curValue) {
    if (depth == 4) {
        if (curValue > maxValue) {
            maxValue = curValue;
        }
        return;
    }

    for (int i=0; i<4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || visited[nextRow][nextCol] == 1) { continue; }
        visited[nextRow][nextCol] = 1;
        searchRest(nextRow, nextCol, depth+1, curValue+board[row][col]);
        visited[nextRow][nextCol] = 0;
    }
}

// T자 모양
void searchT(int row, int col) {
    int curValue;

    // ㅏ 모양
    if (row + 2 < N && col + 1 < M) {
        int curValue = board[row][col] + board[row+1][col] + board[row+2][col] + board[row+1][col+1];
        if (curValue > maxValue) { maxValue = curValue; }
    }

    // ㅓ 모양
    if (row + 2 < N && col - 1 >= 0) {
        int curValue = board[row][col] + board[row+1][col] + board[row+2][col] + board[row+1][col-1];
        if (curValue > maxValue) { maxValue = curValue; }
    }

    // ㅗ 모양
    if (row - 1 >= 0 && col + 2 < M) {
        int curValue = board[row][col] + board[row][col+1] + board[row][col+2] + board[row-1][col+1];
        if (curValue > maxValue) { maxValue = curValue; }
    }

    // ㅜ 모양
    if (row + 1 < N && col + 2 < M) {
        int curValue = board[row][col] + board[row][col+1] + board[row][col+2] + board[row+1][col+1];
        if (curValue > maxValue) { maxValue = curValue; }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    int num;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &num);
            board[i][j] = num;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            visited[i][j] = 1;
            searchRest(i, j, 0, 0);
            visited[i][j] = 0;
            
            searchT(i, j);
        }
    }

    printf("%d", maxValue);

    return 0;
}