#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define BLACK 0
#define WHITE 1

vector<vector<int>> rooms(50, vector<int>(50));
vector<vector<int>> blackCount(50, vector<int>(50, INT_MAX)); // 그동안 지나온 검은 방의 개수를 담는 벡터

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int n, int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string oneLine; 
    for (int i=0; i<n; i++) {
        cin >> oneLine;
        for (int j=0; j<n; j++) {
            rooms[i][j] = oneLine[j] - '0';
        }
    }

    // bfs
    queue<pair<int, int>> q;
    blackCount[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        for (int k=0; k<4; k++) {
            int nextRow = currRow + dr[k];
            int nextCol = currCol + dc[k];
            if (isOutOfRange(n, nextRow, nextCol)) { continue; }
            if (rooms[nextRow][nextCol] == BLACK) {
                if (blackCount[nextRow][nextCol] > blackCount[currRow][currCol] + 1) {
                    blackCount[nextRow][nextCol] = blackCount[currRow][currCol] + 1;
                    q.push({nextRow, nextCol});
                }
            }
            else {
                if (blackCount[nextRow][nextCol] > blackCount[currRow][currCol]) {
                    blackCount[nextRow][nextCol] = blackCount[currRow][currCol];
                    q.push({nextRow, nextCol});
                }
            }
        }
    }

    cout << blackCount[n-1][n-1];

    return 0;
}