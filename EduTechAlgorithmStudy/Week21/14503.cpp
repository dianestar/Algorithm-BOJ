#include <iostream>
#include <vector>
using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// 0:NORTH↑ 1:EAST→ 2:SOUTH↓ 3:WEST← 
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 세로 크기 N과 가로 크기 M
int N, M;

// 로봇청소기가 있는 칸의 좌표 (r,c)와 바라보는 방향 d
struct Robot {
    int r, c, d;
};

Robot robot;
int answer = 0;

bool checkBack(vector<vector<int>> map) {
    // 후진 방향 설정
    int backD;
    if (robot.d == NORTH || robot.d == SOUTH) {
        backD = 2-robot.d; // 0:NORTH <-> 2:SOUTH
    } 
    else { // robot.d == EAST || robot.d == WEST
        backD = 4-robot.d; // 1:EAST <-> 3:WEST
    }
    int backR = robot.r + dr[backD];
    int backC = robot.c + dc[backD];

    // 후진 가능 여부 체크 
    // d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
    if (map[backR][backC] == 1) { // 후진 불가능 (종료)
        return false;
    }
    // c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    else { // 후진 가능 (후진 실시)
        robot.r = backR;
        robot.c = backC;
        return true;
    }
}

void clean(vector<vector<int>> &map) {
    // 1. 현재 위치를 청소한다.
    if (map[robot.r][robot.c] == 0) {
        map[robot.r][robot.c] = -1; // 청소 완료 칸은 -1로 표시
        answer++;
    }

    int nextD = robot.d;
    int nextR, nextC;
    bool cleanAble = false;

    for (int i=0; i<4; i++) {
        // 2. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
        // NORTH -> WEST -> SOUTH -> EAST 순으로 회전
        nextD = (nextD + 3) % 4;
        nextR = robot.r + dr[nextD];
        nextC = robot.c + dc[nextD];

        // a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if (map[nextR][nextC] == 0) {
            robot.r = nextR;
            robot.c = nextC;
            robot.d = nextD;
                
            cleanAble = true;
            break;
        }

        // b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    }

    // cleanAble이 false라면 네 방향 모두 청소가 이미 되어있거나 벽인 경우이므로
    // 뒤쪽 방향의 벽 여부를 체크하여 후진 실시 or 종료가 이루어져야 함
    if (!cleanAble) {
        if (!checkBack(map)) {
            return;
        }
    }

    clean(map);
}


int main() {
    // 첫째 줄 입력
    scanf("%d %d", &N, &M);

    // 둘째 줄 입력
    scanf("%d %d %d", &robot.r, &robot.c, &robot.d);

    // 셋째 줄 이후 입력
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    clean(map);
    printf("%d", answer);

    return 0;
}