#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) {
        return true;
    }
    return false;
}

int solution(vector<vector<int> > maps)
{
    // 0은 벽이 있는 자리, 1은 벽이 없는 자리
    N = maps.size();
    M = maps[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    q.push({0, 0});
    visited[0][0] = 1;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        
        if (curr.first == N-1 && curr.second == M-1) {
            return visited[N-1][M-1];
        }
        
        for (int k=0; k<4; k++) {
            int nextRow = curr.first + dr[k];
            int nextCol = curr.second + dc[k];
            
            if (isOutOfRange(nextRow, nextCol)) { continue; }
            if (maps[nextRow][nextCol] && !visited[nextRow][nextCol]) {
                q.push({nextRow, nextCol});
                visited[nextRow][nextCol] = visited[curr.first][curr.second] + 1;
            }
        }
    }
    
    return -1;
}

int main() {
    // vector<vector<int>> maps = {{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1}};
    vector<vector<int>> maps = {{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,0}, {0,0,0,0,1}};

    printf("%d", solution(maps));
}