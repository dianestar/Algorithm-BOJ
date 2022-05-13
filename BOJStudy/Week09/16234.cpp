#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int N, L, R;
vector<vector<int>> land(50, vector<int>(50)); //  1 ≤ N ≤ 50

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &land[i][j]);
        }
    }

    int days = 0; 

    // 인구 이동이 일어나지 않으면 (isMoved의 값이 false이면) 종료
    int isMoved = true; 
    while (isMoved) {
        isMoved = false;
        vector<vector<int>> visited(N, vector<int>(N, 0));

        // BFS 활용
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!visited[i][j]) {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> unified; // 연합을 이루는 나라의 {행, 열} 값을 담는 벡터

                    visited[i][j] = 1;
                    q.push({i, j});
                    unified.push_back({i, j});
                    int sum = land[i][j];
                    int count = 1;
                    
                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        for (int k=0; k<4; k++) {
                            int nextRow = curr.first + dr[k];
                            int nextCol = curr.second + dc[k];

                            if (isOutOfRange(nextRow, nextCol) || visited[nextRow][nextCol]) { continue; }

                            // cf. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
                            int diff = abs(land[curr.first][curr.second]-land[nextRow][nextCol]);
                            if (diff >= L && diff <=R) {
                                visited[nextRow][nextCol] = 1;
                                q.push({nextRow, nextCol});
                                unified.push_back({nextRow, nextCol});
                                sum += land[nextRow][nextCol];
                                count++;
                            }
                        }
                    }
                    
                    if (count > 1 && !isMoved) { // count가 1보다 클 경우 연합 및 인구 이동이 이루어짐
                        isMoved = true;
                        days++;
                    }

                    // cf. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
                    int average = sum / count;
                    for (int k=0; k<unified.size(); k++) {
                        land[unified[k].first][unified[k].second] = average;
                    }
                }
            }
        }
    }

    // cf. 인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.
    printf("%d", days);

    return 0;
}