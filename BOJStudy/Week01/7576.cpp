#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<vector<int>> box(1000, vector<int>(1000));
int M, N;
int days;

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &M, &N);

    int validTomato = 0;
    int emptySquare = 0;
    queue<pair<int, int>> q;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1) {
                q.push({i, j});
                validTomato++;
            }
            else if (box[i][j] == -1) {
                emptySquare++;
            }
        }
    }

    int totalTomato = N * M - emptySquare;
    
    while (!q.empty()) {
        if (totalTomato == validTomato) {
            break;
        }

        days++;
        int qSize = q.size();
        int prevValidTomato = validTomato;
    
        for (int i=0; i<qSize; i++) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int k=0; k<4; k++) {
                int nextRow = curr.first + dr[k];
                int nextCol = curr.second + dc[k];
                if (!isOutOfRange(nextRow, nextCol) && box[nextRow][nextCol] == 0) {
                    box[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol});
                    validTomato++;
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (box[i][j] == 0) {
                days = -1;
                break;
            }
        }
    }

    printf("%d", days);

    return 0;
}