#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 0: x좌표가 증가하는 방향 (→) 1: y좌표가 감소하는 방향 (↑) 2: x좌표가 감소하는 방향 (←) 3: y좌표가 증가하는 방향 (↓)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vector<int>> matrix(101, vector<int>(101, 0));
int answer = 0;

void drawCurve(int x, int y, int d, int g) {
    vector<int> dirs;

    // 0세대 드래곤 커브 
    matrix[x][y] = 1;
    x += dx[d];
    y += dy[d];
    matrix[x][y] = 1;
    dirs.push_back(d);
    
    // 1~N세대 드래곤 커브
    for (int i=0; i<g; i++) {
        for (int j=dirs.size()-1; j>=0; j--) {
            d = (dirs[j] + 1) % 4;
            x += dx[d];
            y += dy[d];
            matrix[x][y] =  1;
            dirs.push_back(d);
        }
    }
}

void checkCurve() {
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (matrix[i][j] && matrix[i+1][j] && matrix[i][j+1] && matrix[i+1][j+1]) {
                answer++;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int x, y, d, g;
    for (int i=0; i<N; i++) {
        // x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대
        scanf("%d %d %d %d", &x, &y, &d, &g);
        drawCurve(x, y, d, g);
    }

    checkCurve();
    
    printf("%d", answer);

    return 0;
}