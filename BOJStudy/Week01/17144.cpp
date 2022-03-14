#include <iostream>
#include <vector>
using namespace std;

int R, C, T;
int totalDust = 0; // T초 후 남아있는 미세먼지의 양
vector<vector<int>> room(50, vector<int>(50));
vector<int> cleanerRow; // 공기청정기의 행 인덱스

// 위쪽 오른쪽 아래쪽 왼쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= R || col < 0 || col >= C) { 
        return true;
    }
    return false;
}

void spreadDust() {
    // 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
    vector<vector<int>> nextRoom(50, vector<int>(50, 0));
    nextRoom[cleanerRow[0]][0] = -1;
    nextRoom[cleanerRow[1]][0] = -1;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            int dust = room[i][j];
            if (dust == -1 || dust == 0) { continue; }

            // (r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
            int spreadCount = 0; // 확산이 일어난 방향의 개수
            for (int k=0; k<4; k++) {
                int adjRow = i + dr[k];
                int adjCol = j + dc[k];

                // 인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
                if (isOutOfRange(adjRow, adjCol) || room[adjRow][adjCol] == -1) { continue; }

                // 확산되는 양은 Ar,c/5이고 소수점은 버린다.
                nextRoom[adjRow][adjCol] += dust / 5;
                spreadCount++;
            }

            // (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
            nextRoom[i][j] += (dust - dust / 5 * spreadCount);
        }
    }

    room = nextRoom;
}

void cleanAir() {
    // 공기청정기로 들어간 미세먼지는 모두 정화된다.
    room[cleanerRow[0]-1][0] = 0;
    room[cleanerRow[1]+1][0] = 0;

    // 위쪽 공기청정기의 바람은 반시계방향으로 순환한다.
    for (int i=cleanerRow[0]-1; i>0; i--) { room[i][0] = room[i-1][0]; } // ↓
    for (int i=0; i<C-1; i++) { room[0][i] = room[0][i+1]; } // ←
    for (int i=0; i<cleanerRow[0]; i++) { room[i][C-1] = room[i+1][C-1]; } // ↑
    for (int i=C-1; i>1; i--) { room[cleanerRow[0]][i] = room[cleanerRow[0]][i-1]; } // →
    room[cleanerRow[0]][1] = 0;

    // 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
    for (int i=cleanerRow[1]+1; i<R-1; i++) { room[i][0] = room[i+1][0]; } // ↑
    for (int i=0; i<C-1; i++) { room[R-1][i] = room[R-1][i+1]; } // ←
    for (int i=R-1; i>cleanerRow[1]-1; i--) { room[i][C-1] = room[i-1][C-1]; } // ↓
    for (int i=C-1; i>1; i--) { room[cleanerRow[1]][i] = room[cleanerRow[1]][i-1]; } // →
    room[cleanerRow[1]][1] = 0;
}

void getTotalDust() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (room[i][j] == -1 ||  room[i][j] == 0) { continue; }
            totalDust += room[i][j];
        }
    }
}

int main() {
    // 입력
    scanf("%d %d %d", &R, &C, &T);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%d", &room[i][j]);

            // 공기청정기 위치 저장
            // 공기청정기는 항상 1번 열에 설치되어 있고, 크기는 두 행을 차지한다. 
            if (room[i][j] == -1) {
                cleanerRow.push_back(i);
            }
        }
    }

    // T초가 지난 후 구사과의 방에 남아있는 미세먼지의 양 구하기
    for (int i=0; i<T; i++) {
        // 1초 동안 일어나는 일 1. 미세먼지 확산 2.공기청정기 작동
        spreadDust();
        cleanAir();
    }
    getTotalDust();

    printf("%d", totalDust);

    return 0;
}