#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> heights(100, vector<int>(100));
vector<vector<int>> visited(100, vector<int>(100));

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

void dfs(int row, int col, int rain) {
    visited[row][col] = 1;
    for (int i=0; i<4; i++) {
        int nextRow = row + dr[i];
        int nextCol = col + dc[i];
        if (!isOutOfRange(nextRow, nextCol) && heights[nextRow][nextCol] > rain && !visited[nextRow][nextCol]) {
            dfs(nextRow, nextCol, rain);
        }
    }
}

int main() {
    scanf("%d", &N);

    int num;
    int maxHeight = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &num);
            heights[i][j] = num;
            if (num > maxHeight) {
                maxHeight = num;
            }
        }
    }

    int maxSecure = 1;
    for (int rain=1; rain<maxHeight; rain++) {
        int curSecure = 0;
        if (rain != 1) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    visited[i][j] = 0;
                }
            }
        }
    
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (heights[i][j] > rain && !visited[i][j]) {
                    dfs(i, j, rain);
                    curSecure++;
                }
            }
        }
        if (curSecure > maxSecure) {
            maxSecure = curSecure;
        }
    }

    printf("%d", maxSecure);

    return 0;
}