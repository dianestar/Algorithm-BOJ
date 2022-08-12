#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Camera { 
    int num; // CCTV 번호
    int row; // 행 인덱스
    int col; // 열 인덱스
    int dir; // 방향
};

int N;
int M;
int camerasCount;
int minBlindSpot = 2147483647;
vector<vector<int>> originOffice(8, vector<int>(8));
vector<vector<int>> copiedOffice(8, vector<int>(8));
vector<Camera> cameras;

// 위 왼쪽 아래 오른쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

void checkDir(int dir, int row, int col) {
    while (1) {
        row += dr[dir];
        col += dc[dir];    

        if (isOutOfRange(row, col) || copiedOffice[row][col] == 6) { break; }
        if (copiedOffice[row][col] >= 1 && copiedOffice[row][col] <= 5) { continue; }
        copiedOffice[row][col] = 7; // 감시할 수 있는 영역 표시
    }
}

void checkWatchingSpace() {
    copiedOffice = originOffice;

    for (int i=0; i<camerasCount; i++) {
        int num = cameras[i].num;
        int dir = cameras[i].dir;
        int row = cameras[i].row;
        int col = cameras[i].col;

        if (num == 1) { // 무조건 한 방향
            checkDir(dir, row, col);
        }
        else if (num == 2) { // 반대 방향으로 두 방향
            checkDir(dir, row, col);
            checkDir(abs(2 - dir), row, col);
        }
        else if (num == 3) { // 직각 방향으로 두 방향
            checkDir(dir, row, col);
            checkDir((dir + 1) % 4, row, col);
        }
        else if (num == 4) { // 한쪽 방향 제외하고 세 방향
            for (int j=0; j<4; j++) {
                if (j == dir) { continue; }
                checkDir(j, row, col);
            }
        }
        else if (num == 5) { // 무조건 네 방향 모두
            for (int j=0; j<4; j++) {
                checkDir(j, row, col);
            }
        }
    }
}

void countBlindSpot() {
    int curBlindSpot = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copiedOffice[i][j] == 0) { curBlindSpot++; }
        }
    }
    if (curBlindSpot < minBlindSpot) { minBlindSpot = curBlindSpot; }
}

void changeCameraDir(int idx) {
    if (idx == camerasCount) {
        checkWatchingSpace();
        countBlindSpot();
        return;
    }

    cameras[idx].dir = 0;
    changeCameraDir(idx + 1);

    cameras[idx].dir = 1;
    changeCameraDir(idx + 1);

    cameras[idx].dir = 2;
    changeCameraDir(idx + 1);

    cameras[idx].dir = 3;
    changeCameraDir(idx + 1); 
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &originOffice[i][j]);
            if (originOffice[i][j] >= 1 && originOffice[i][j] <= 5) {
                cameras.push_back({originOffice[i][j], i, j, -1});
            }
        }
    }

    camerasCount = cameras.size();
    changeCameraDir(0);

    printf("%d", minBlindSpot);

    return 0;
}