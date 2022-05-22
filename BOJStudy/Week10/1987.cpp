#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int maxCount = 0;
int R, C;
vector<string> board;
vector<int> visited(26);

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= R || col < 0 || col >= C) {
        return true;
    }
    return false;
}

void dfs(int row, int col, int count) {
    if (count > maxCount) { maxCount = count; }

    for (int k=0; k<4; k++) {
        int nextRow = row + dr[k];
        int nextCol = col + dc[k];
        if (isOutOfRange(nextRow, nextCol) || visited[board[nextRow][nextCol] - 'A']) { continue; }
        visited[board[nextRow][nextCol] - 'A'] = 1;
        dfs(nextRow, nextCol, count+1);
        visited[board[nextRow][nextCol] - 'A'] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    string str;
    for (int i=0; i<R; i++) {
        cin >> str;
        board.push_back(str);
    }
    
    visited[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << maxCount;

    return 0;
}