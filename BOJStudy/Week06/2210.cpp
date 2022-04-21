#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<vector<int>> board(5, vector<int>(5));
unordered_set<int> availableNumbers;

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= 5 || col < 0 || col >= 5) {
        return true;
    }
    return false;
}

void search(int row, int col, int depth, int number) {
    if (depth == 5) {
        availableNumbers.insert(number);
        return;
    }

    for (int i=0; i<4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];

        if (isOutOfRange(nextRow, nextCol)) { continue; }
        search(nextRow, nextCol, depth+1, number*10+board[nextRow][nextCol]);
    }
}

int main() {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            search(i, j, 0, board[i][j]);
        }
    }

    printf("%d", availableNumbers.size());

    return 0;
}