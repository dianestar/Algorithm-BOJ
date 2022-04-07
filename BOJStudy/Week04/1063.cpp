#include <iostream>
#include <string>

using namespace std;

#define MAX_IDX 8

// R L B T RT LT RB LB
int dr[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

// 열은 가장 왼쪽 A~오른쪽 H, 행은 가장 아래 1~위 8
// {row, col}
pair<int, int> kingPos;
pair<int, int> stonePos;

bool isOutOfRange(int row, int col) {
    if (row <= 0 || row > MAX_IDX || col <=0 || col > MAX_IDX) {
        return true;
    }
    return false;
}

void move(string cmd) {
    int flag;
    if (cmd == "R") { flag = 0; }
    else if (cmd == "L") { flag = 1; }
    else if (cmd == "B") { flag = 2; }
    else if (cmd == "T") { flag = 3; }
    else if (cmd == "RT") { flag = 4; }
    else if (cmd == "LT") { flag = 5; }
    else if (cmd == "RB") { flag = 6; }
    else if (cmd == "LB") { flag = 7;}

    int nextRow = kingPos.first + dr[flag];
    int nextCol = kingPos.second + dc[flag];

    // 킹이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
    if (isOutOfRange(nextRow, nextCol)) { return; }

    // 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
    if (nextRow == stonePos.first && nextCol == stonePos.second) {
        int nextStoneRow = stonePos.first + dr[flag];
        int nextStoneCol = stonePos.second + dc[flag];

        // 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.
        if (isOutOfRange(nextStoneRow, nextStoneCol)) { return; }

        stonePos.first = nextStoneRow;
        stonePos.second = nextStoneCol;
    }
    
    kingPos.first = nextRow;
    kingPos.second = nextCol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 알파벳은 열을 상징하고, 숫자는 행을 상징
    string king, stone;
    int N;
    cin >> king >> stone >> N;

    kingPos.first = king[1] - '0';
    kingPos.second = king[0] - 'A' + 1;
    stonePos.first = stone[1] - '0';
    stonePos.second = stone[0] - 'A' + 1;
    
    string cmd;
    for (int i=0; i<N; i++) {
        cin >> cmd;
        move(cmd);
    }

    char kingCol = kingPos.second - 1 + 'A';
    char stoneCol = stonePos.second - 1 + 'A';
    cout << kingCol << kingPos.first << "\n";
    cout << stoneCol << stonePos.first << "\n";
    
    return 0;
}