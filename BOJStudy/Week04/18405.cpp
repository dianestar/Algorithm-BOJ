#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int N, K;
vector<vector<int>> board(201, vector<int>(201));

struct Virus {
    int number;
    int row;
    int col;
    int second;
};

struct Cmp {
    bool operator()(const Virus &a, const Virus &b) {
        if (a.second == b.second) {
            return a.number > b.number;
        }
        return a.second > b.second;
    }
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &N, &K);

    int virusNum;
    priority_queue<Virus, vector<Virus>, Cmp> pq;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &virusNum);
            board[i][j] = virusNum;
            if (virusNum != 0) {
                pq.push({virusNum, i, j, 0});
            }
        }
    }

    int S, X, Y;
    scanf("%d %d %d", &S, &X, &Y);

    for (int i=1; i<=S; i++) {
        if (pq.empty()) { break; }

        int pqSize = pq.size();
        for (int j=0; j<pqSize; j++) {
            Virus virus = pq.top();
            pq.pop();
            
            for (int k=0; k<4; k++) {
                int nextRow = virus.row + dr[k];
                int nextCol = virus.col + dc[k];
                
                if (isOutOfRange(nextRow, nextCol)) { continue; }
                if (board[nextRow][nextCol] != 0) { continue; }

                board[nextRow][nextCol] = virus.number;
                pq.push({virus.number, nextRow, nextCol, i});
            }
        }
    }

    printf("%d", board[X-1][Y-1]);

    return 0;
}