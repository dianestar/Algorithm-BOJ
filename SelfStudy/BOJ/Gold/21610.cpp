#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 50
#define MAX_M 100

int N, M, d, s;
vector<vector<int>> A(MAX_N, vector<int>(MAX_N));
vector<vector<int>> visited(MAX_N, vector<int>(MAX_N, 0));
vector<pair<int, int>> isCloud;

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void initializeCloud() {
    isCloud.push_back({N-1, 0});
    isCloud.push_back({N-1, 1});
    isCloud.push_back({N-2, 0});
    isCloud.push_back({N-2, 1});
}

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) return true;
    return false;
}

int convertRange(int idx) {
    if (idx < 0) {
        while (idx < 0) idx = N + idx;
    }
    if (idx >= N) {
        while (idx >= N) idx = idx - N;
    }
    return idx;
}

void increaseWater() {
    d -= 1;

    for (int i=0; i<isCloud.size(); i++) {
        // 1. 모든 구름이 di 방향으로 si칸 이동한다.
        int nextRow = isCloud[i].first + dr[d] * s;
        int nextCol = isCloud[i].second + dc[d] * s;

        if (isOutOfRange(nextRow, nextCol)) {
            nextRow = convertRange(nextRow);
            nextCol = convertRange(nextCol);
        }
        
        // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
        isCloud[i] = {nextRow, nextCol};
        A[nextRow][nextCol]++;
        visited[nextRow][nextCol] = 1;

        // 3. 구름이 모두 사라진다.
    }
}

void copybugWater() {
    // 4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
    // 이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
    // 예를 들어, (N, 2)에서 인접한 대각선 칸은 (N-1, 1), (N-1, 3)이고, (N, N)에서 인접한 대각선 칸은 (N-1, N-1)뿐이다.
    for (int i=0; i<isCloud.size(); i++) {
        int count = 0;

        for (int j=1; j<8; j+=2) {
            int targetRow = isCloud[i].first + dr[j];
            int targetCol = isCloud[i].second + dc[j];

            if (isOutOfRange(targetRow, targetCol)) continue;     
            if (A[targetRow][targetCol]) count++;
        }

        A[isCloud[i].first][isCloud[i].second] += count;
    }
}

void createCloud() {
    // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
    isCloud.clear();

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (A[i][j] >= 2 && !visited[i][j]) {
                isCloud.push_back({i, j});
                A[i][j] -= 2;
            }
        }
    }

    vector<vector<int>> newVisited(MAX_N, vector<int>(MAX_N, 0));
    visited = newVisited;
}

int getWaterSum() {
    int sum = 0;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sum += A[i][j];
        }
    }
    
    return sum;
}

/*
void printA() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
*/

int main() {
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    initializeCloud();

    for (int i=0; i<M; i++) {
        scanf("%d %d", &d, &s);
        increaseWater();
        copybugWater();
        createCloud();
    }

    int answer = getWaterSum();
    printf("%d", answer);

    return 0;
}