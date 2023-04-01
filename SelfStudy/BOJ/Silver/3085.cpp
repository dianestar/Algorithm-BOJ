#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char board[50][50];
vector<pair<int, int>> idx;
int maxCount = 0;

int dr[2] = {1, 0};
int dc[2] = {0, 1};

void checkMax() {
    int count;

    // 가장 긴 행 탐색
    for (int i=0; i<N; i++) {
        count = 1;
        for (int j=1; j<N; j++) {
            if (board[i][j] == board[i][j-1]) {
                count++;
            }
            else {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }

    // 가장 긴 열 탐색
    for (int i=0; i<N; i++) {
        count = 1;
        for (int j=1; j<N; j++) {
            if (board[j-1][i] == board[j][i]) {
                count++;
            }
            else {
                maxCount = max(maxCount, count);
                count = 1;
            }
        }
        maxCount = max(maxCount, count);
    }
}

void chooseCandy() {
    int idxSize = idx.size();
    int row, col, adjRow, adjCol;

    for (int i=0; i<idxSize; i++) {
        row = idx[i].first;
        col = idx[i].second;

        for (int j=0; j<2; j++) {
            // cf) 상근이는  사탕의 색이 다른 인접한 두 칸을 고른다.
            // j가 0일 때는 아래쪽 탐색 (세로로 swap), j가 1일 때는 오른쪽 탐색 (가로로 swap) 
            adjRow = row + dr[j];
            adjCol = col + dc[j];

            // 인접한 칸이 보드 크기의 범위 밖이거나 인접한 칸에 들어있는 사탕의 색이 같을 경우 continue
            if (adjRow < 0 || adjRow >=N || adjCol < 0 || adjCol >=N || board[row][col] == board[adjRow][adjCol]) { continue; }

            // cf) 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다.
            swap(board[row][col], board[adjRow][adjCol]);

           // cf) 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분을 고른 다음 그 사탕을 모두 먹는다.
            checkMax();

            // 교환했던 사탕 제자리로 복원
            swap(board[row][col], board[adjRow][adjCol]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    char c;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> c;
            board[i][j] = c;
            idx.push_back({i,j});
        }
    }
    chooseCandy();
    cout << maxCount;

    return 0;
}