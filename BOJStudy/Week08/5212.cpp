#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= R || col < 0 || col >= C) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    string line;
    vector<string> currentMap;
    for (int i=0; i<R; i++) {
        cin >> line;
        currentMap.push_back(line);
    }

    vector<string> futureMap = currentMap;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (currentMap[i][j] == 'X') {
                int adjSea = 0;
                for (int k=0; k<4; k++) {
                    int nextRow = i + dr[k];
                    int nextCol = j + dc[k];
                    if (isOutOfRange(nextRow, nextCol)) {
                        adjSea++;
                        continue;
                    }
                    if (currentMap[nextRow][nextCol] == '.') { adjSea++; }
                }
                if (adjSea >= 3) { futureMap[i][j] = '.'; }
            }
        }
    }

    int startRow = R;
    int endRow = -1;
    int startCol = C;
    int endCol = -1;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (futureMap[i][j] == 'X') {
                startRow = min(startRow, i);
                endRow = max(endRow, i);
                startCol = min(startCol, j);
                endCol = max(endCol, j);
            }
        }
    }

    for (int i=startRow; i<=endRow; i++) {
        for (int j=startCol; j<=endCol; j++) {
            cout << futureMap[i][j];
        }
        cout << "\n";
    }


    return 0;
}