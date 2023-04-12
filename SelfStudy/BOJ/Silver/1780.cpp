#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_N (pow(3, 7))

vector<vector<int>> paper(MAX_N, vector<int>(MAX_N));
vector<int> answer(3);

void checkPaper(int row, int col, int N) {
    int flag = paper[row][col];

    for (int i=row; i<row+N; i++) {
        for (int j=col; j<col+N; j++) {
            if (paper[i][j] != flag) {
                int nextN = N / 3;
                checkPaper(row, col, nextN);
                checkPaper(row, col + nextN, nextN);
                checkPaper(row, col + 2 * nextN, nextN);
                checkPaper(row + nextN, col, nextN);
                checkPaper(row + nextN, col + nextN, nextN);
                checkPaper(row + nextN, col + 2 * nextN, nextN);
                checkPaper(row + 2 * nextN, col, nextN);
                checkPaper(row + 2 * nextN, col + nextN, nextN);
                checkPaper(row + 2 * nextN, col + 2 * nextN, nextN);
                return;
            }
        }
    }
    answer[flag+1]++;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    checkPaper(0, 0, N);

    for (int i=0; i<3; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}