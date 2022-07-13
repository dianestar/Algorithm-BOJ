#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;

// 가장 처음에 주사위에는 모든 면에 0이 적혀져 있음
// dice[1]~dice[6]: 윗면 북쪽 동쪽 서쪽 남쪽 바닥
/*
  2
4 1 3
  5
  6
*/
vector<int> dice(7, 0); 
vector<int> nextDice(7);

// 동쪽 서쪽 북쪽 남쪽
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// 주사위는 지도의 바깥으로 이동시킬 수 없음
bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

void rollDice(int cmd) {
    if (cmd == 0) { // 동쪽
        nextDice[6] = dice[3];
        nextDice[3] = dice[1];
        nextDice[1] = dice[4];
        nextDice[4] = dice[6];
    }
    else if (cmd == 1) { // 서쪽
        nextDice[6] = dice[4];
        nextDice[4] = dice[1];
        nextDice[1] = dice[3];
        nextDice[3] = dice[6];
    }
    else if (cmd == 2) { // 북쪽
        nextDice[6] = dice[2];
        nextDice[2] = dice[1];
        nextDice[1] = dice[5];
        nextDice[5] = dice[6];
    }
    else if (cmd == 3) { // 남쪽
        nextDice[6] = dice[5];
        nextDice[5] = dice[1];
        nextDice[1] = dice[2];
        nextDice[2] = dice[6];
    }
}

int main() {
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    vector<vector<int>> map(N, vector<int>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    int cmd;
    for (int i=0; i<K; i++) {
        scanf("%d", &cmd);
        cmd--;

        if (isOutOfRange(x+dx[cmd], y+dy[cmd])) { continue; }

        x += dx[cmd];
        y += dy[cmd];
        rollDice(cmd);

        // i) 이동한 칸에 쓰여 있는 수가 0인 경우
        if (map[x][y] == 0) {
            // 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
            map[x][y] = nextDice[6];
        }
        
        // ii) 이동한 칸에 쓰여 있는 수가 0이 아닌 경우
        else {
            // 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사 + 칸에 쓰여 있는 수는 0이 됨
            nextDice[6] = map[x][y];
            map[x][y] = 0;
        }

        // 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력
        printf("%d\n", nextDice[1]);

        dice = nextDice;
    }

    return 0;
}