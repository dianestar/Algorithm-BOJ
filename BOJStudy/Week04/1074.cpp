#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, r, c;
int answer;

void drawZ(int row, int col, int powN) { // {row, col}은 현재 사분면의 탐색 시작점
    if (row == r && col == c) {
        printf("%d", answer);
        return;
    }
    
    // {r, c}가 현재 사분면에 없는 경우
    // 현재 사분면을 한 칸씩 탐색해볼 필요 없음
    if (r < row || r >= row+powN || c < col || c >= col+powN) {
        answer += powN * powN;
        return;
    }

    // {r, c}가 현재 사분면에 있는 경우
    // 현재 사분면을 재귀적으로 분할하여 탐색
    int halfPowN = powN / 2; // powN이 2^N이라면 halfPowN은 2^(N-1)
    drawZ(row, col, halfPowN);
    drawZ(row, col+halfPowN, halfPowN);
    drawZ(row+halfPowN, col, halfPowN);
    drawZ(row+halfPowN, col+halfPowN, powN);    
}

int main() {
    scanf("%d %d %d", &N, &r, &c);
    drawZ(0, 0, pow(2, N));

    return 0;
}