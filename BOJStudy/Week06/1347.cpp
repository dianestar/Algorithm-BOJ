#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0은 이동할 수 있는 칸(.) vs 1은 벽(#)
vector<vector<int>> board(101, vector<int>(101, 1));

// 아래쪽 왼쪽 위쪽 오른쪽
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cout.tie(NULL);

    int N;
    cin >> N;

    string cmd;
    cin >> cmd;

    int row = 50;
    int col = 50;
    board[row][col] = 0;

    int minRow = row;
    int minCol = col;
    int maxRow = row;
    int maxCol = col;
    int dir = 0;
    
    for (int i=0; i<N; i++) {
        if (cmd[i] == 'R') {
            dir = (dir+1) % 4;
        }
        else if (cmd[i] == 'L') {
            dir = (dir+3) % 4;
        }
        else if (cmd[i] == 'F') {
            row += dr[dir];
            col += dc[dir];
            board[row][col] = 0;

            minRow = min(minRow, row);
            minCol = min(minCol, col);
            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
        }
    }

    for (int i=minRow; i<=maxRow; i++) {
        for (int j=minCol; j<=maxCol; j++) {
            if (board[i][j] == 0) { cout << '.'; }
            else { cout  << '#'; }
        }
        cout << "\n";
    }

    return 0;
}