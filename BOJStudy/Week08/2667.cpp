#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<string> house(N);
    for (int i=0; i<N; i++) {
        cin >> house[i];
    }

    vector<vector<int>> visited(N, vector<int>(N, 0));
    vector<int> houseCount;
    int totalDivision = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (house[i][j] == '1' && !visited[i][j]) {
                totalDivision++;

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                int currCount = 1; 

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    
                    for (int k=0; k<4; k++) {
                        int nextRow = curr.first + dr[k];
                        int nextCol = curr.second + dc[k];

                        if (isOutOfRange(nextRow, nextCol)) { continue; }
                        if (house[nextRow][nextCol] == '1' && !visited[nextRow][nextCol]) {
                            q.push({nextRow, nextCol});
                            visited[nextRow][nextCol] = 1;
                            currCount++;
                        }
                    }
                }

                houseCount.push_back(currCount);
            }
        }
    }

    cout << totalDivision << "\n";
    sort(houseCount.begin(), houseCount.end());
    for (int i=0; i<totalDivision; i++) {
        cout << houseCount[i] << "\n";
    }

    return 0;
}