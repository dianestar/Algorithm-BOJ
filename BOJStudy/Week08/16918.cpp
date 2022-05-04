#include <iostream>
#include <string>
#include <vector>
using namespace std;

int R, C, N;
vector<vector<int>> grid(200, vector<int>(200, 0)); // 빈칸: 0 vs 폭탄: 1~3 

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= R || col < 0 || col >= C) { return true; }
    return false;
}

void convertGridInput(vector<string> gridInput) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (gridInput[i][j] == 'O') { grid[i][j] = 1; }
        }
    }
}

void printGridOutput() {
    for (int i=0; i<R; i++) {
        string temp = "";
        for (int j=0; j<C; j++) {
            if (grid[i][j] == 0) { temp += '.'; }
            else { temp += 'O'; }
        }
        cout << temp << "\n";
    }
}

void doNothing() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (grid[i][j] != 0) { grid[i][j]++; }
        }
    }
}

void installBomb() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            grid[i][j]++;
        }
    }
}

void explode() {
    vector<vector<int>> nextGrid(R, vector<int>(C, -1));

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (grid[i][j] == 3) {
                nextGrid[i][j] = 0;
                for (int k=0; k<4; k++) {
                    int nextRow = i + dr[k];
                    int nextCol = j + dc[k];
                    if (isOutOfRange(nextRow, nextCol)) { continue; }
                    nextGrid[nextRow][nextCol] = 0;
                }
            }

            if (nextGrid[i][j] == -1) { nextGrid[i][j] = ++grid[i][j]; }
        }
    }
    
    grid = nextGrid;
}

/*
void printGrid() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> N;

    string line;
    vector<string> gridInput;
    for (int i=0; i<R; i++) {
        cin >> line;
        gridInput.push_back(line);
    }

    // 1. 가장 처음에 봄버맨은 일부 칸에 폭탄을 설치해 놓는다.
    convertGridInput(gridInput);
    
    int time = 0;
    while (time < N) {
        time++;

        // 2. 다음 1초 동안 봄버맨은 아무것도 하지 않는다.
        if (time == 1) { doNothing(); }

        // 3. 다음 1초 동안 폭탄이 설치되어 있지 않은 모든 칸에 폭탄을 설치한다.
        else if (time % 2 == 0) { installBomb(); }

        // 4. 1초가 지난 후에 3초 전에 설치된 폭탄이 모두 폭발한다.
        else { explode(); }

        // 5. 3과 4를 반복한다.
    }

    // 총 R개의 줄에 N초가 지난 후의 격자판 상태를 출력한다.
    printGridOutput();

    return 0;
}