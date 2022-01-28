/* 스터디에서 얻은 Tip을 반영하여 수정해본 코드 */
// 먹을 수 있는 "모든" 물고기에 대해 탐색 X
// "bfs queue의 현재 사이즈만큼의 횟수만" 탐색해본 후 먹을 수 있는 물고기가 있는지 확인 시 
// <같은 최소 거리에 있는 물고기들에 대해서만 탐색> 하고 멈출 수 있어서 효율성이 높아진다

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_INDEX 20
#define MAX_DIST 400

struct Shark {
    int row, column, num, size;
};

Shark shark;

int N;
int matrix[20][20];
int dist[20][20];
int time = 0;

// 위쪽 왼쪽 아래쪽 오른쪽
int moveRow[4] = {-1, 0, 1, 0};
int moveCol[4] = {0, -1, 0, 1};


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    
    return a.first < b.first;
}

void solution() {
    while (1) {
        // minDist, minRow, minCol 값 초기화
        int minRow = MAX_INDEX;
        int minCol = MAX_INDEX;
        int minDist = MAX_DIST;

        // dist 행렬 초기화 후 현재 shark 위치의 dist 행렬 값 0으로 설정
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                dist[i][j] = -1;
            }
        }
        dist[shark.row][shark.column] = 0;

        // bfs queue 초기화 후 큐에 현재 shark 위치 push
        queue<pair<int, int>> distChecker;
        distChecker.push({shark.row, shark.column});

        // bfs
        while (!distChecker.empty()) {
            vector<pair<int, int>> minCandidates;
            int queueSize = distChecker.size();

            for (int i=0; i<queueSize; i++) { // queueSize 변수 및 해당 for문을 추가한 것이 수정의 핵심
                pair<int, int> curr = distChecker.front();
                distChecker.pop();

                for (int i=0; i<4; i++) {
                    int nextRow = curr.first + moveRow[i];
                    int nextCol = curr.second + moveCol[i];

                    // cf) 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
                    // nextRow 또는 nextCol 값이 matrix 범위 밖으로 벗어나거나 matrix[nextRow][nextCol]이 지나갈 수 없는 칸이거나 이미 거리 값을 체크한 칸일 경우 스킵
                    // dist[nextRow][nextCol] !=1 조건식으로 bfs visited 여부 체크
                    if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N 
                    || matrix[nextRow][nextCol] > shark.size || dist[nextRow][nextCol] != -1) { 
                        continue;
                    }

                    // 지나갈 수 있거나 먹을 수 있는 칸에 대해 거리 값 체크 및 해당 좌표 bfs queue에 push
                    dist[nextRow][nextCol] = dist[curr.first][curr.second] + 1;
                    distChecker.push({nextRow, nextCol});

                    // 먹을 수 있는 물고기를 minCandidates에 push
                    if (matrix[nextRow][nextCol] != 0 && matrix[nextRow][nextCol] < shark.size) {    
                        minCandidates.push_back({nextRow, nextCol});
                    }
                }
            }

            // minCandidates가 존재할 경우 타겟 선정
            if (minCandidates.size() != 0) {
                if (minCandidates.size() != 1) { // cf) 거리가 가까운 물고기가 많다면, 
                    sort(minCandidates.begin(), minCandidates.end(), cmp); // 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다. (cmp 함수로 구현)
                }
                minRow = minCandidates[0].first;
                minCol = minCandidates[0].second;
                minDist = dist[minRow][minCol];
                break;
            }
        }

        if (minDist == MAX_DIST) { // 더 이상 먹을 수 있는 물고기가 공간에 없다면 종료
            break;
        }

        // 물고기를 먹는 부분
        // cf) 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.
        shark.row = minRow;
        shark.column = minCol;
        shark.num++;
        matrix[minRow][minCol] = 0;
        // cf) 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
        if (shark.num == shark.size) {
            shark.num = 0;
            shark.size++;
        }

        // 시간 업데이트
        time += minDist;
    }
    
}

int main() {
    scanf("%d", &N);

    int status;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &status);
            matrix[i][j] = status;

            if (status == 9) {
                matrix[i][j] = 0;
                shark.row = i;
                shark.column = j;
                shark.num = 0;
                shark.size = 2;
            }
        }
    }

    solution();
    printf("%d", time);

    return 0;
}