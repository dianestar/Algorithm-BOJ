#include <iostream>
#include <vector>
using namespace std;

int answer = 11;

//moving direction
//[flag] : [0] 왼쪽으로 기울이기, [1] 오른쪽으로 기울이기, [2] 위쪽으로 기울이기, [3] 아래쪽으로 기울이기
int moveR[4] = {0, 0, -1, 1};
int moveC[4] = {-1, 1, 0, 0};

struct MovedResult {
    bool isOut;
    int row, column;
};

bool isRedFirst(int rR, int rC, int bR, int bC, int flag) {
    if (flag == 0) { return rC < bC; } //왼쪽
    else if (flag == 1) { return rC > bC; } //오른쪽
    else if (flag == 2) { return rR < bR; } //위쪽
    else if (flag == 3) { return rR > bR; } //아래쪽
}

MovedResult move(vector<vector<char>> &tempBoard, int row, int column, int flag, char c) {
    //printf("flag: %d\n", flag);
    bool isOut = false;

    if (tempBoard[row+moveR[flag]][column+moveC[flag]] == '.' || tempBoard[row+moveR[flag]][column+moveC[flag]] == 'O') {
        //맨 처음 움직이기 시작할 때 애초에 움직일 수 있는지 여부를 체크
        //움직일 수 있을 경우 원래 위치의 R 또는 B 를 . 으로 바꿔주고 움직이기 시작
        tempBoard[row][column] = '.';
    }

    while (tempBoard[row+moveR[flag]][column+moveC[flag]] == '.') { 
        //다음 칸이 .(빈칸)일 경우 움직일 수 있는 만큼 움직임
        row += moveR[flag];
        column += moveC[flag];
    }

    if (tempBoard[row+moveR[flag]][column+moveC[flag]] == 'O') {
        //다음 칸이 O(구멍)일 경우 빠져나옴
        isOut = true;
    }
    else {
        //다음 칸이 #(벽또는장애물)이거나 R 또는 B로 막혀있을 경우 지금 자리가 이번 턴에서 움직인 최종 자리
        tempBoard[row][column] = c;
    }

    MovedResult movedResult = {isOut, row, column};
    return movedResult;
}

void search(vector<vector<char>> &board, int rR, int rC, int bR, int bC, int flag, int count) {
    //printf("count: %d\n", count);
    if (count > 10 || count >= answer) {
        return;
    }

    for (int i=0; i<4; i++) {
        if (i == flag) {
            continue;
        }

        vector<vector<char>> tempBoard = board;
        MovedResult redResult, blueResult;
        if (isRedFirst(rR, rC, bR, bC, i)) {
            //printf("RED FIRST\n");
            redResult = move(tempBoard, rR, rC, i, 'R');
            blueResult = move(tempBoard, bR, bC, i, 'B');
            //printf("redResult: %d %d %d\n", redResult.isOut, redResult.row, redResult.column);
            //printf("blueResult: %d %d %d\n", blueResult.isOut, blueResult.row, blueResult.column);
        }
        else {
            //printf("BLUE FIRST\n");
            blueResult = move(tempBoard, bR, bC, i, 'B');
            redResult = move(tempBoard, rR, rC, i, 'R');
            //printf("blueResult: %d %d %d\n", blueResult.isOut, blueResult.row, blueResult.column);
            //printf("redResult: %d %d %d\n", redResult.isOut, redResult.row, redResult.column);
        }

        if (!blueResult.isOut && redResult.isOut) {
            //printf("success\n");
            answer = count;
            return;
        }
        else if (!blueResult.isOut && !redResult.isOut) {
            search(tempBoard, redResult.row, redResult.column, blueResult.row, blueResult.column, i, count+1);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);


    int rR, rC, bR, bC; //redRow, redColumn, blueRow, blueColumn
    char c;
    vector<vector<char>> board;
    for (int i=0; i<N; i++) {
        vector<char> v;
        scanf(" ", c); //개행문자 무시
        for (int j=0; j<M; j++) {
            //. 빈칸   # 장애물또는벽   o 구멍   R 빨간구슬   B 파란구슬
            scanf("%c", &c); 
            v.push_back(c);

            //구슬일 경우 위치 index 저장
            if (c == 'R') { rR = i; rC = j; }
            else if (c == 'B') { bR = i; bC = j; }
        }
        board.push_back(v);
    }

    search(board, rR, rC, bR, bC, -1, 1);

    if (answer == 11) {
        answer = -1;
    }
    printf("%d", answer);

    return 0;
}