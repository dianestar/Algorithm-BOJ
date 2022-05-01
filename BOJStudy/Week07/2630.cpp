#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper(128, vector<int>(128));
vector<int> paperCount(2);

void divideAndConquer(int row, int col, int len) {
    int flag = paper[row][col];

    for (int i=row; i<row+len; i++) {
        for (int j=col; j<col+len; j++) {
            if (paper[i][j] != flag) {
                len /= 2;

                divideAndConquer(row, col, len);
                divideAndConquer(row+len, col, len);
                divideAndConquer(row, col+len, len);
                divideAndConquer(row+len, col+len, len);
                
                return;
            }
        }
    }

    paperCount[flag]++;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    divideAndConquer(0, 0, N);

    printf("%d\n%d", paperCount[0], paperCount[1]);

    return 0;
}