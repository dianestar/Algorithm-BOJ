#include <iostream>
#include <vector>
using namespace std;

int notSecure;
int n, m;
vector<vector<pair<int, int>>> indexVec(3);
vector<vector<int>> board(1001, vector<int>(1001));

int drK[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dcK[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int drQ[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dcQ[8] = {0, 0, -1, 1, -1, 1, -1, 1};

bool isOutOfRange(int row, int col) {
    if (row <= 0 || row > n || col <= 0 || col > m) {
        return true;
    }
    return false;
}

void moveKnight(int row, int col) {
    for (int i=0; i<8; i++) {
        int nextRow = row + drK[i];
        int nextCol = col + dcK[i];
        if (!isOutOfRange(nextRow, nextCol) && board[nextRow][nextCol] != -1 && board[nextRow][nextCol] != -2) {
            board[nextRow][nextCol] = -2;
            notSecure++;
        }
    }
}

void moveQueen(int row, int col) {
    int originRow = row;
    int originCol = col;

    for (int i=0; i<8; i++) {
        int nextRow = row + drQ[i];
        int nextCol = col + dcQ[i];

        if (isOutOfRange(nextRow, nextCol) || board[nextRow][nextCol] == -1) {
            row = originRow;
            col = originCol;
            continue;
        }
        if (board[nextRow][nextCol] != -2) {
            board[nextRow][nextCol] = -2;
            notSecure++;
        }
        row = nextRow;
        col = nextCol;
        i--;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int count, r, c;
    for (int i=0; i<3; i++) { // Q K P 순서
        scanf("%d", &count);
        notSecure += count;
        for (int j=0; j<count; j++) {
            scanf("%d %d", &r, &c);
            indexVec[i].push_back({r, c});
            board[r][c] = -1;
        }
    }

    for (int i=0; i<indexVec[0].size(); i++) {
        moveQueen(indexVec[0][i].first, indexVec[0][i].second);
    }

    for (int i=0; i<indexVec[1
    ].size(); i++) {
        moveKnight(indexVec[1][i].first, indexVec[1][i].second);
    }

    printf("%d", (n*m-notSecure));

    return 0;
}