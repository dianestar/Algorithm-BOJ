#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int answer;
vector<int> board(15); // board[i]: i행에 놓여 있는 queen 위치의 열 인덱스

bool isValid(int r) {
    for (int i=0; i<r; i++) {
        // 같은 열에 위치하거나 대각선 상에 위치할 경우 invalid
        if (board[i] == board[r] || (r-i) == abs(board[r] - board[i])) {
            return false;
        }
    }
    return true;
}

void setQueen(int r) {
    if (r == N) {
        // N개의 queen을 놓는 데 성공했다면 answer++
        answer++;
        return;
    }

    for (int c=0; c<N; c++) {
        board[r] = c;
        // { r, c }에 queen을 놓는 것이 valid할 경우 다음 행 r+1에 queen을 놓을 위치 탐색
        if (isValid(r)) { setQueen(r+1); }
    }
}

int main() {
    // cf) 퀸은 자신을 기준으로 상하좌우 + 대각선으로 이동 및 공격 가능
    scanf("%d", &N);
    setQueen(0);
    printf("%d", answer);
    return 0;
}