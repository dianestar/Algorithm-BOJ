#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    
    // 채울 행, 열 숫자
    int row = 0;
    int col = 0;
    int number = 1;
    
    // 행 축 움직이는 범위
    int minRow = 0;
    int maxRow = n-1;
    
    // row == maxRow일 때 순차적으로 채워넣을 열의 최소/최대 인덱스
    int minCol = 0;
    int maxCol = n-1;
    
    // 채워질 숫자의 최댓값 = 1 + 2 + 3 + ... + n
    int maxNumber = 0;
    for (int i=1; i<=n; i++) { maxNumber += i; }
    
    while (number <= maxNumber) {
        // ↙ 방향
        col = minCol;
        for (row=minRow; row<maxRow; row++) {
            matrix[row][col] = number;
            number++;
        }
        minRow++;

        // → 방향
        for (col=minCol; col<=maxCol; col++) {
            matrix[row][col] = number;
            number++;
        }
        maxRow--;
        minCol += 1;
        maxCol -= 2;
        
        // ↖ 방향
        col -= 2;
        for (row=maxRow; row>=minRow; row--) {
            matrix[row][col] = number;
            number++;
            col--;
        }
        minRow++;
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j] != 0) { answer.push_back(matrix[i][j]); }
        }
    }
    
    return answer;
}

int main() {
    vector<int> n = {4, 5, 6};

    for (int i=0; i<n.size(); i++) {
        vector<int> answer = solution(n[i]);

        for (int j=0; j<answer.size(); j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }

    return 0;
}