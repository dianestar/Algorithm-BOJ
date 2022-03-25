#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int maxSafe;
vector<vector<int>> map(8, vector<int>(8));
vector<pair<int, int>> candidates;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

void spreadAndCount(vector<vector<int>> tempMap) {
    vector<vector<int>> visited(8, vector<int>(8, 0));

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tempMap[i][j] == 2) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    for (int k=0; k<4; k++) {
                        int nextRow = curr.first + dr[k];
                        int nextCol = curr.second + dc[k];
                        if (isOutOfRange(nextRow, nextCol) || tempMap[nextRow][nextCol] == 1 || visited[nextRow][nextCol]) {

                            continue;
                        }
                        if (tempMap[nextRow][nextCol] == 0) {
                            tempMap[nextRow][nextCol] = 2;
                        }
                        q.push({nextRow, nextCol});
                        visited[nextRow][nextCol] = 1;
                    }
                }
            }
        }
    }
    int curSafe = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (tempMap[i][j] == 0) {
                curSafe++;
            }
        }
    }
    if (curSafe > maxSafe) {
        maxSafe = curSafe;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) {
                candidates.push_back({i, j});
            }
        }
    }

    int size = candidates.size();
    vector<bool> isSelected;
    for (int i=0; i<size-3; i++) { isSelected.push_back(0); }
    for (int i=0; i<3; i++) { isSelected.push_back(1); }
    do {
        vector<vector<int>> tempMap(8, vector<int>(8));
        tempMap = map;
        for (int i=0; i<size; i++) {
            if (isSelected[i]) {
                tempMap[candidates[i].first][candidates[i].second] = 1;
            }
        }
        spreadAndCount(tempMap);
    } while(next_permutation(isSelected.begin(), isSelected.end()));

    printf("%d", maxSafe);

    return 0;
}