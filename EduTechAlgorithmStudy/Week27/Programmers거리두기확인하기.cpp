#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> answer;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= 5 || col < 0 || col >= 5) {
        return true;
    }
    return false;
}

void scanRoom(vector<string> room) {
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (room[i][j] == 'P') { // bfs
                queue<pair<int, int>> q;
                vector<vector<bool>> visited(5, vector<bool>(5, false));
                q.push({i, j});
                visited[i][j] = true;
                
                int distance = 0;
                while (distance < 2) {
                    int queueSize = q.size();
                    pair<int, int> curr = q.front();
                    q.pop();
                    
                    for (int k=0; k<queueSize; k++) {
                        for (int l=0; l<4; l++) {
                            int nextRow = curr.first + dr[l];
                            int nextCol = curr.second + dc[l];
                            
                            if (isOutOfRange(nextRow, nextCol) || visited[nextRow][nextCol]) { continue; }
                            if (room[nextRow][nextCol] == 'X') { continue; }
                            if (room[nextRow][nextCol] == 'P') {
                                // 한 명이라도 거리두기를 지키지 않고 있으면 0
                                answer.push_back(0);
                                return;
                            }
                            
                            q.push({nextRow, nextCol});
                            visited[nextRow][nextCol] = true;
                        }
                    }
                    distance++;
                }
            }
        }
    }
    // 모든 응시자가 거리두기를 지키고 있으면 1
    answer.push_back(1);
}

vector<int> solution(vector<vector<string>> places) {
    for (int i=0; i<places.size(); i++) {
        scanRoom(places[i]);
    }    
    
    return answer;
}

int main() {
    vector<vector<string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    vector<int> answer = solution(places);
    for (int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}