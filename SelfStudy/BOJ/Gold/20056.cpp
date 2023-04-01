#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_N 50

struct Fireball {
    int r, c, m, s, d;
};

int N, M, K;
vector<vector<vector<Fireball>>> matrix(MAX_N, vector<vector<Fireball>>(MAX_N, vector<Fireball>()));
vector<Fireball> fireballList;

// ↑ ↗ → ↘ ↓ ↙ ← ↖
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) return true;
    return false;
}

int convertOutIdx(int idx) {
    while (idx < 0) idx += N;
    while (idx >= N) idx -= N;
    return idx;
}

void initializeMatrix() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            matrix[i][j].clear();
        }
    }
}

void moveAll() {
    for (int i=0; i<fireballList.size(); i++) {
        Fireball fireball = fireballList[i];

        // 1. 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
        int nextRow = fireball.r + dr[fireball.d] * fireball.s;
        int nextCol = fireball.c + dc[fireball.d] * fireball.s;

        if (isOutOfRange(nextRow, nextCol)) {
            nextRow = convertOutIdx(nextRow);
            nextCol = convertOutIdx(nextCol);
        }

        // 1-a. 이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있다.        
        matrix[nextRow][nextCol].push_back({nextRow, nextCol, fireball.m, fireball.s, fireball.d});
        fireballList[i].r = nextRow;
        fireballList[i].c = nextCol;
    }
}

void processTwoOrMore() {
    vector<Fireball> newFireballList;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int len = matrix[i][j].size();

            if (len == 0) continue;
            if (len == 1) newFireballList.push_back(matrix[i][j][0]);

            // 2. 이동이 모두 끝난 뒤, 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
            if (len >= 2) {
                // 1) 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
                int newM = 0;
                int newS = 0;
                int newD = matrix[i][j][0].d % 2;
                bool isEven = true;

                for (int k=0; k<len; k++) {
                    newM += matrix[i][j][k].m;
                    newS += matrix[i][j][k].s;
                    if (matrix[i][j][k].d % 2 != newD) isEven = false;
                }

                // 2) 파이어볼은 4개의 파이어볼로 나누어진다.
                // 3) 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
                // -> 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
                newM = floor(newM / 5);

                // -> 질량이 0인 파이어볼은 소멸되어 없어진다.
                if (newM == 0) continue;

                // -> 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
                newS = floor(newS / len);

                // -> 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                if (isEven) {
                    for (int k=0; k<8; k+=2) {
                        newFireballList.push_back({i, j, newM, newS, k});
                    }
                }
                else {
                    for (int k=1; k<8; k+=2) {
                        newFireballList.push_back({i, j, newM, newS, k});                        
                    }
                }
            }
        }
    }

    fireballList = newFireballList;
}

int calculateTotalM() {
    int sum =0;

    for (int i=0; i<fireballList.size(); i++) {
        sum += fireballList[i].m;
    }

    return sum;
}

int main () {
    scanf("%d %d %d", &N, &M, &K);

    Fireball fireball;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d %d %d", &fireball.r, &fireball.c, &fireball.m, &fireball.s, &fireball.d);
        fireball.r--;
        fireball.c--;
        matrix[fireball.r][fireball.c].push_back(fireball);
        fireballList.push_back(fireball);
    }

    while (K > 0) {
        initializeMatrix();
        moveAll();
        processTwoOrMore();
        K--;
    }

    printf("%d", calculateTotalM());

    return 0;
}