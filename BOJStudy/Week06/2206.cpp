#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info {
    int row;
    int col;
    int count;
    int chance;
};

int N;
int M;
vector<vector<int>> map(1000, vector<int>(1000, -1));
vector<vector<vector<bool>>> visited(1000, vector<vector<bool>>(1000, vector<bool>(2, false))); 
// cf. visited[][][0]: 벽을 깬 상태의 방문 여부 vs visited[][][1]: 벽을 깨지 않은 상태의 방문 여부

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

int bfs() {  
    queue<Info> q;
    q.push({0, 0, 1, 1});
    visited[0][0][1] = true;

    while (!q.empty()) {
        int qSize = q.size();
        for (int i=0; i<qSize; i++) {
            Info curr = q.front();
            q.pop();
            
            if (curr.row == N-1 && curr.col == M-1) {
                return curr.count;
            }
            
            for (int j=0; j<4; j++) {
                int nextRow = curr.row + dr[j];
                int nextCol = curr.col + dc[j];

                if (isOutOfRange(nextRow, nextCol)) { continue; }
                if (map[nextRow][nextCol] == 0 && !visited[nextRow][nextCol][curr.chance]) {
                    q.push({nextRow, nextCol, curr.count+1, curr.chance});
                    visited[nextRow][nextCol][curr.chance] = true;
                }
                else if (map[nextRow][nextCol] == 1 && curr.chance) {
                    q.push({nextRow, nextCol, curr.count+1, curr.chance-1});
                    visited[nextRow][nextCol][curr.chance-1] = true;
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string oneLine;
    for (int i=0; i<N; i++) {
        cin >> oneLine;
        for (int j=0; j<M; j++) {
            map[i][j] = oneLine[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}