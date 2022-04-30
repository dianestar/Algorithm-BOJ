#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMin(int a, int b, int c) {
    int minNum = min(a, b);
    return min(minNum, c);
}

int solution(vector<vector<int>> board)
{
    int len = board[0][0];

    int n = board.size();
    int m = board[0].size();

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (board[i][j]) {
                // ← ↖ ↑ 위치의 값 중에서 가장 작은 값 + 1
                board[i][j] = getMin(board[i][j-1], board[i-1][j-1], board[i-1][j]) + 1;
                len = max(len, board[i][j]);
            }
        }
    }

    return len * len;
}

int main() {
    vector<vector<int>> board = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 1, 0}
    };

    /*
    vector<vector<int>> board = {
        {0, 0, 1, 1},
        {1, 1, 1, 1}
    };
    */

    printf("%d", solution(board));

    return 0;
}