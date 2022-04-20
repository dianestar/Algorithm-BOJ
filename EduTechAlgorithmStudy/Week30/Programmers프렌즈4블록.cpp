#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 오른쪽 아래 오른쪽아래 현위치
int dr[4] = {0, 1, 1, 0};
int dc[4] = {1, 0, 1, 0};

bool isOutOfRange(int m, int n, int row, int col) {
    if (row < 0 || row >= m || col < 0 || col >= n) {
        return true;
    }
    return false;
}

int solution(int m, int n, vector<string> board) {    
    int totalCount = 0;

    vector<vector<bool>> blocksToErase(m, vector<bool>(n, false));
    while (1) {
        // initialization
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                blocksToErase[i][j] = false;
            }
        }

        // check blocks to erase
        int curCount = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] != '0') {
                    bool yesErase = true;
                    for (int k=0; k<3; k++) {
                        int nextRow = i + dr[k];
                        int nextCol = j + dc[k];

                        if (isOutOfRange(m, n, nextRow, nextCol)) {
                            yesErase = false;
                            break;
                        }

                        if (board[nextRow][nextCol] != board[i][j]) {
                            yesErase = false;
                            break;
                        }
                    }
                    
                    if (yesErase) {
                        for (int k=0; k<4; k++) {
                            if (!blocksToErase[i+dr[k]][j+dc[k]]) {
                                curCount++;
                                blocksToErase[i+dr[k]][j+dc[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        
        // decide to exit or not
        if (curCount == 0) { break; }
        else { totalCount += curCount;}

        // do erase
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (blocksToErase[i][j]) { board[i][j] = '0'; }
            }
        }
        
        // go downward
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '0') {
                    int k = i;
                    while (k-1 >=0 && board[k-1][j] != '0') {
                        board[k][j] = board[k-1][j];
                        board[k-1][j] = '0';
                        k--;
                    }
                }
            }
        }
    }
    
    int answer = totalCount;
    return answer;
}

int main() {
    vector<int> m = {4, 6, 4};
    vector<int> n = {5, 6, 4};
    vector<vector<string>> board = {{"CCBDE", "AAADE", "AAABF", "CCBBF"}, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}, {"ABCD", "BACE", "BCDD", "BCDD"}};

    for (int i=0; i<m.size(); i++) {
        printf("%d\n", solution(m[i], n[i], board[i]));
    }

    return 0;
}