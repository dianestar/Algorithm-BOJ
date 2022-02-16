#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N; // 지도의 크기 N (100 이하의 자연수)
int islandId= 0; // 섬을 구분하기 위한 id
int minBridge = 10001; // 가장 짧은 다리의 길이
struct AdjSea { // 육지에 인접한 바다 칸의 정보
    int row;
    int col;
    int adjIsland;
};
vector<AdjSea> adjSeaList;
vector<vector<bool>> visited(100, vector<bool>(100));
vector<vector<int>> map(100, vector<int>(100)); // N*N 크기의 지도

// 위쪽 오른쪽 아래쪽 왼쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool checkRange(int i, int j) {
    if (i<0 || i>=N || j<0 || j>=N) {
        return false;
    }
    return true;
}

/* 섬 구분하기 */ 
void firstBFS(int i, int j, int islandId) {
    queue<pair<int, int>> q;
    q.push({i, j});
    map[i][j] = islandId;
    visited[i][j] = true;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int k=0; k<4; k++) { // 동서남북 네 방향에 대해 탐색
            int nr = cur.first + dr[k];
            int nc = cur.second + dc[k];
            if (!checkRange(nr, nc) || visited[nr][nc]) { // 지도 범위 밖이거나 이미 방문한 칸일 경우
                continue;
            } 
            if (map[nr][nc] != 0) { // 인접한 칸이 육지일 경우
                q.push({nr, nc});
                map[nr][nc] = islandId;
                visited[nr][nc] = true;
            }
            else { // 인접한 칸이 바다일 경우 (map[nr][nc] == 0)
                adjSeaList.push_back({nr, nc, islandId});
                visited[nr][nc] = true;
            }
        }
    }
}

void identifyIsland() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] != 0 && !visited[i][j]) {
                islandId++;
                firstBFS(i, j, islandId);
            } 
        }
    }
}
/************/

/* 다리 놓기 */ 
void secondBFS(int i, int j, int adjIsland) {
    // firstBFS에서 사용한 visited 벡터 초기화
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int curBridge = 1; // 현재 놓는 다리의 길이

    while (!q.empty()) {
        int queueSize = q.size();
        for (int k=0; k<queueSize; k++) { // 최단 거리를 구해야하므로 현재 큐의 사이즈만큼만 탐색
            pair<int, int> cur = q.front();
            q.pop();
            for (int l=0; l<4; l++) { // 동서남북 네 방향에 대해 탐색
                int nr = cur.first + dr[l];
                int nc = cur.second + dc[l];
                if (!checkRange(nr, nc) || visited[nr][nc]) { continue; } // 지도 범위 밖이거나 이미 방문한 칸일 경우
                if (map[nr][nc] == 0) { // 인접한 칸이 바다일 경우
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
                else if (map[nr][nc] != adjIsland) { // 인접한 칸이 다른 섬의 육지일 경우
                    if (curBridge < minBridge) { minBridge = curBridge; }
                    return;
                }
            }
        }
        curBridge++;
    }
}

void buildBridge() {
    int len = adjSeaList.size();
    for (int i=0; i<len; i++) {
        secondBFS(adjSeaList[i].row, adjSeaList[i].col, adjSeaList[i].adjIsland);
    }
}
/************/

int main() {
    scanf("%d", &N);
    int num;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &num);
            map[i][j] = num; 
        }
    }

    identifyIsland(); // 섬 구분하기
    buildBridge(); // 다리 놓기

    printf("%d", minBridge);

    return 0;
}