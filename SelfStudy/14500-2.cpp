// solution #2
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[500][500];
int maxValue = 0;

int dr[19][4] = {
    // ㅡ 모양과 ㅡ 계열 회전 및 대칭 모양
    {0, 0, 0, 0}, {0, 1, 2, 3},

    // ㅁ 모양과 ㅁ 계열 회전 및 대칭 모양
    {0, 0, 1, 1}, 
    
    // L 모양과 L 계열 회전 및 대칭 모양
    {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 0, -1},
    {0, 0, -1, -2}, {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 1, 1, 1},

    // S 모양과 S 계열 회전 및 대칭 모양
    {0, 1, 1, 2}, {0, 0, 1, 1},
    {0, 1, 1, 2}, {0, 0, 1, 1},

    // ㅜ 모양과 ㅜ 계열 회전 및 대칭 모양
    {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 1, 2, 1}
};

int dc[19][4] = {
    // ㅡ 모양과 ㅡ 계열 회전 및 대칭 모양
    {0, 1, 2, 3}, {0, 0, 0, 0},

    // ㅁ 모양과 ㅁ 계열 회전 및 대칭 모양
    {0, 1, 0, 1},

    // L 모양과 L 계열 회전 및 대칭 모양
    {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 1, 1, 1}, {0, 1, 2, 2},
    {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2},

    // S 모양과 S 계열 회전 및 대칭 모양
    {0, 0, 1, 1}, {0, 1, 0, -1}, {0, 0, -1, -1}, {0, 1, 1, 2},

    // ㅜ 모양과 ㅜ 계열 회전 및 대칭 모양
    {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 0, 0, -1}
};

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
            for (int k=0; k<19; k++) { // 총 19가지의 모양에 대해 탐색 실시
                int curValue = 0;
                for (int l=0; l<4; l++) {
                    int nextRow = i+dr[k][l];
                    int nextCol = j+dc[k][l];
                    if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) { break; }
                    curValue += board[nextRow][nextCol];
                }
                maxValue = max(maxValue, curValue);
            }
        }
    }

    printf("%d", maxValue);

    return 0;
}