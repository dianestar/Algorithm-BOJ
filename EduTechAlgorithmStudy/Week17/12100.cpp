#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define UP 0 //상
#define DOWN 1 //하
#define LEFT 2 //좌
#define RIGHT 3 //우

int N;
int maxBlock;

/*
void printVector(vector<vector<int>> board) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
*/

vector<vector<int>> moveUpDown(vector<vector<int>> board, int flag) {
    //Up or Down: 열을 기준으로 같은 열에 있는 행 값들을 Merge
    int startPoint, endPoint, direction;
    if (flag == UP) { startPoint = 0; endPoint = N; direction = 1; } //[0]행 쪽으로 Merge
    else if (flag == DOWN) { startPoint = N-1; endPoint = -1; direction = -1; } //[N-1]행 쪽으로 Merge

    for (int j=0; j<N; j++) { //[i][j] i 행 j 열
        deque<int> dq; //매 열에서 이루어지는 Merge 결과 저장
        bool isMerged = false; //이전 단계에서 블록이 이미 합쳐졌는지 체크하는 변수
        /* cf) 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다 */
        for (int i=startPoint; i!=endPoint; i+=direction) {
            if (board[i][j] != 0) {
                if (!dq.empty() && dq.back() == board[i][j] && !isMerged) {
                    //이전 블록과 합쳐질 수 있는 경우
                    dq.pop_back();
                    int MergedNum = board[i][j]*2;
                    dq.push_back(MergedNum);
                    if (MergedNum > maxBlock) {
                        maxBlock = MergedNum;
                    }
                    isMerged = true;
                }
                else {
                    //이전 블록과 합쳐질 수 없는 경우
                    dq.push_back(board[i][j]);
                    isMerged = false;
                }
            }
        }
        for (int i=startPoint; i!=endPoint; i+=direction) {
            if (!dq.empty()) {
                //Merge 결과값들로 board의 해당 열 값 변경
                board[i][j] = dq.front();
                dq.pop_front();
            }
            else {
                //해당 열의 남은 공간들은 0으로 변경
                board[i][j] = 0;
            }
        }
    }

    return board;
}

vector<vector<int>> moveLeftRight(vector<vector<int>> board, int flag) {
    //Left or Right: 행을 기준으로 같은 행에 있는 열 값들을 Merge
    int startPoint, endPoint, direction;
    if (flag == LEFT) { startPoint = 0; endPoint = N; direction = 1; } //[0]열 쪽으로 Merge
    else if (flag == RIGHT) { startPoint = N-1; endPoint = -1; direction = -1; } //[N-1]열 쪽으로 Merge

    for (int i=0; i<N; i++) {
        deque<int> dq; //매 행에서 이루어지는 combination 결과 저장
        bool isMerged = false; //이전 단계에서 블록이 이미 합쳐졌는지 체크하는 변수
        /* cf) 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다 */
        for (int j=startPoint; j!=endPoint; j+=direction) {
            if (board[i][j] != 0) {
                if (!dq.empty() && dq.back() == board[i][j] && !isMerged) {
                    //이전 블록과 합쳐질 수 있는 경우
                    dq.pop_back();
                    int MergedNum = board[i][j]*2;
                    dq.push_back(MergedNum);
                    if (MergedNum > maxBlock) {
                        maxBlock = MergedNum;
                    }
                    isMerged = true;
                }
                else {
                    //이전 블록과 합쳐질 수 없는 경우
                    dq.push_back(board[i][j]);
                    isMerged = false;
                }
            }
        }
        for (int j=startPoint; j!=endPoint; j+=direction) {
            if (!dq.empty()) {
                //Merge 결과값들로 해당 행 값 변경
                board[i][j] = dq.front();
                dq.pop_front();
            }
            else {
                //해당 행의 남은 공간들은 0으로 변경
                board[i][j] = 0;
            }
        }
    }

    return board;
}

void play(vector<vector<int>> board, int count) {
    if (count > 5) {
        //최대 5번 이동
        return;
    }

    //상하좌우 움직이기 재귀적으로 호출
    play(moveUpDown(board, UP), count+1);
    play(moveUpDown(board, DOWN), count+1);
    play(moveLeftRight(board, LEFT), count+1);
    play(moveLeftRight(board, RIGHT), count+1);
}

int main() {
    scanf("%d", &N);

    int num;
    vector<vector<int>> board;
    for (int i=0; i<N; i++) {
        vector<int> v;
        for (int j=0; j<N; j++) {
            scanf("%d", &num);
            v.push_back(num);
            if (num > maxBlock) {
                maxBlock = num;
            }
        }
        board.push_back(v);
    }

    play(board, 1);

    printf("%d", maxBlock);

    return 0;
}