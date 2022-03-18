#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int isBlind;
int isNotBlind;
vector<vector<char>> picture(100, vector<char>(100));
vector<vector<bool>> visited(100, vector<bool>(100));

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

void bfs(char color, int row, int col) {
    vector<pair<int, int>> candidates;
    queue<pair<int, int>> q;
    visited[row][col] = true;
    q.push({row, col});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int k=0; k<4; k++) {
            int nextRow = curr.first + dr[k];
            int nextCol = curr.second + dc[k];
            if (isOutOfRange(nextRow, nextCol) || visited[nextRow][nextCol]) { continue; }
            if (picture[nextRow][nextCol] == color) {
                visited[nextRow][nextCol] = true;
                q.push({nextRow, nextCol});
            }
            else if (color == 'R' && picture[nextRow][nextCol] == 'G' || color == 'G' && picture[nextRow][nextCol] == 'R') {
                candidates.push_back({nextRow, nextCol});
            }
        }
    }

    for (int i=0; i<candidates.size(); i++) {
        
        int r = candidates[i].first;
        int c = candidates[i].second;
        if (!visited[r][c]) {
            isNotBlind++;
            bfs(picture[r][c], r, c);
        }
    }
}

int main() {
    char newLine;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%c", &newLine);
        for (int j=0; j<N; j++) {
            scanf("%c", &picture[i][j]);
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!visited[i][j] && (picture[i][j] == 'R' || picture[i][j] == 'G' || picture[i][j] == 'B')) {
                isBlind++;
                isNotBlind++;
                bfs(picture[i][j], i, j);
            }
        }
    }

    printf("%d %d", isNotBlind, isBlind);


    return 0;
}