#include <iostream>
#include <vector>
using namespace std;

int answer;
int H, W;
vector<vector<int>> world(500, vector<int>(500));

bool isLeftRightValid(int row, int col) {
    int left = col;
    int right = col;

    bool leftValid = false;
    bool rightValid = false;

    while (left >= 0) {
        if (world[row][left] == 1) {
            leftValid = true;
            break;
        }
        left--;
    }

    while (right < W) {
        if (world[row][right] == 1) {
            rightValid = true;
            break;
        }
        right++;
    }

    if (leftValid && rightValid) { return true; }
    return false;
}

int main() {
    scanf("%d %d", &H, &W);

    int h;
    for (int i=0; i<W; i++) {
        scanf("%d", &h);
        for (int j=0; j<h; j++) {
            world[j][i] = 1;
        }
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (world[i][j] == 0 && isLeftRightValid(i, j)) {
                answer++;
            }
        }
    }

    printf("%d", answer);

    return 0;
}