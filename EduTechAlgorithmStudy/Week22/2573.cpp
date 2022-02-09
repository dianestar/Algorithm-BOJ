#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> sea(300, vector<int>(300)); 
vector<vector<bool>> visited(300, vector<bool>(300)); 
int iceCount; // 현재 sea 벡터에서 0이 아닌 값이 저장된 칸의 개수
int curCount; // search 함수로 탐색한 한 덩어리 속 0이 아닌 값이 저장된 칸의 개수

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<vector<int>> decrease() {
    vector<vector<int>> nextSea(300, vector<int>(300, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (sea[i][j] != 0) {
                int zeroCount = 0; // 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수
                for (int k=0; k<4; k++) {
                    if (sea[i+dr[k]][j+dc[k]] == 0) {
                        zeroCount++;
                    }
                }

                // cf) 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 
                nextSea[i][j] = sea[i][j] - zeroCount;
                if (nextSea[i][j] <= 0) {
                    // cf) 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 
                    nextSea[i][j] = 0;
                    iceCount--;
                }
            }
        }
    }
    return nextSea;
}

void initialize() {
    // visited 벡터와 curCount 변수 초기화
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            visited[i][j] = false;
        }
    }
    curCount = 0;
}

void search(int i, int j) {
    // dfs
    visited[i][j] = true;
    curCount++;
    for (int k=0; k<4; k++) {
        int nextRow = i+dr[k];
        int nextCol = j+dc[k];
        if (sea[nextRow][nextCol] != 0 && !visited[nextRow][nextCol]) {
            search(nextRow, nextCol);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    int num;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &num);
            sea[i][j] = num;
            if (num != 0) {
                iceCount++;
            }
        }
    }

    int year = 0;
    while (1) {
        // cf) 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.
        if (iceCount == 0) {
            printf("0");
            break;
        }

        bool endFlag = false;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (sea[i][j] != 0) { // 0이 아닌 값이 저장된 임의의 칸 지정
                    initialize(); // 새로운 연도의 빙산 상태 탐색을 위해 초기화
                    search(i, j); // 해당 칸이 포함된 한 덩어리의 0이 아닌 칸의 개수 탐색
                    endFlag = true;
                    break;
                }
            }
            if (endFlag) {
                break;
            }
        }
        if (curCount != iceCount) { // 빙산이 두 덩어리 이상으로 분리된 경우
            printf("%d", year);
            break;
        }
        
        sea = decrease(); // 빙산의 높이 감소
        year++;
    }

    return 0;
}