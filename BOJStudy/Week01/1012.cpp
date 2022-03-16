#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> answers;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

int main() {
    int T, K;
    scanf("%d", &T);

    for (int tc=0; tc<T; tc++) {
        scanf("%d %d %d", &M, &N, &K);
        
        vector<vector<int>> field(N, vector<int>(M, 0));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        int x, y;
        for (int i=0; i<K; i++) {
            scanf("%d %d", &x, &y);
            field[y][x] = 1;
        }

        int answer = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (field[i][j] && !visited[i][j]) {
                    answer++; 

                    // bfs
                    queue<pair<int, int>> q;
                    visited[i][j] = true;
                    q.push({i, j});

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        for (int k=0; k<4; k++) {
                            int nr = curr.first + dr[k];
                            int nc = curr.second + dc[k];

                            if (!isOutOfRange(nr, nc) && field[nr][nc] && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        answers.push_back(answer);
    }
    
    for (int tc=0; tc<T; tc++) {
        printf("%d\n", answers[tc]);
    }

    return 0;
}