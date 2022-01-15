#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_INDEX 20
#define MAX_DIST 400

struct Shark {
    int row, column, num, size;
};

Shark shark;

int N;
int matrix[20][20];
int dist[20][20];
int time = 0;

// 위쪽 왼쪽 아래쪽 오른쪽
int moveRow[4] = {-1, 0, 1, 0};
int moveCol[4] = {0, -1, 0, 1};

void solution() {
    queue<pair<int, int>> distChecker;

    while (1) {
        //dist 행렬 초기화
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dist[i][j] = -1;
            }
        }
        dist[shark.row][shark.column] = 0;

        /* check distance (bfs) */
        distChecker.push({shark.row, shark.column});
        while (!distChecker.empty()) {
            pair<int, int> curr = distChecker.front();
            distChecker.pop();

            for (int i=0; i<4; i++) {
                int nextRow = curr.first + moveRow[i];
                int nextCol = curr.second + moveCol[i];

                // cf) 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
                // nextRow 또는 nextCol 값이 matrix 범위 밖으로 벗어나거나 matrix[nextRow][nextCol]이 지나갈 수 없는 칸이거나 이미 거리 값을 체크한 칸일 경우 스킵
                if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N 
                || matrix[nextRow][nextCol] > shark.size || dist[nextRow][nextCol] != -1) { 
                    continue;
                }

                // 거리 값 체크 및 해당 좌표 bfs queue에 push
                dist[nextRow][nextCol] = dist[curr.first][curr.second] + 1;
                distChecker.push({nextRow, nextCol});
            }
        }

        /* choose target */
        //minDist, minRow, minCol 값 초기화
        int minDist = MAX_DIST;
        int minRow = MAX_INDEX;
        int minCol = MAX_INDEX;

        // cf) 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.
        // cf) 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (matrix[i][j] < shark.size && matrix[i][j] != 0 && dist[i][j] != -1 && dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
        }

        if (minDist == MAX_DIST) { // 더 이상 먹을 수 있는 물고기가 공간에 없다면 종료
            break;
        }

        /* eat fish */
        // cf) 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.
        shark.row = minRow;
        shark.column = minCol;
        shark.num++;
        matrix[minRow][minCol] = 0;

        // cf) 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
        if (shark.num == shark.size) {
            shark.num = 0;
            shark.size++;
        }

        time += minDist;
    }
    
}

int main() {
    scanf("%d", &N);

    int status;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &status);
            matrix[i][j] = status;

            if (status == 9) {
                matrix[i][j] = 0;
                shark.row = i;
                shark.column = j;
                shark.num = 0;
                shark.size = 2;
            }
        }
    }

    solution();
    printf("%d", time);

    return 0;
}