#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int dr[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= h || col < 0 || col >= w) {
        return true;
    }
    return false;
}

int main() {
    vector<int> islands;

    while (scanf("%d %d", &w, &h)) {
        if (w == 0 && h == 0) {
            break;
        }
        vector<vector<int>> map(h, vector<int>(w));
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int island = 0;
        vector<vector<int>> visited(h, vector<int>(w, 0));
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                if (!visited[i][j] && map[i][j]) {
                    island++;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        for (int k=0; k<8; k++) {
                            int nextRow = curr.first + dr[k];
                            int nextCol = curr.second + dc[k];

                            if (isOutOfRange(nextRow, nextCol)) { continue; }

                            if (!visited[nextRow][nextCol] && map[nextRow][nextCol]) {
                                q.push({nextRow, nextCol});
                                visited[nextRow][nextCol] = 1;
                            }
                        }
                    }
                }
            }
        }
        islands.push_back(island);
    }
    
    for (int i=0; i<islands.size(); i++) {
        printf("%d\n", islands[i]);
    }

    return 0;
}