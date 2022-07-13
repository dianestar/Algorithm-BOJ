#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // row * columns 크기의 행렬 초기화
    vector<vector<int>> matrix(rows, vector<int>(columns));
    int num = 1;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            matrix[i][j] = num;
            num++;
        }
    }
    
    for (int i=0; i<queries.size(); i++) {
        int x1 = queries[i][0]-1;
        int y1 = queries[i][1]-1;
        int x2 = queries[i][2]-1;
        int y2 = queries[i][3]-1;
        
        // (원본을 훼손 시키기 않고) 회전 결과를 따로 담을 벡터 초기화
        vector<vector<int>> nextMatrix(rows, vector<int> (columns));
        copy(matrix.begin(), matrix.end(), nextMatrix.begin());
        
        // 행렬에 있는 최댓값으로 초기화
        int minNum = rows * columns; 
        
        // → 행(x1)은 같고 열++
        for (int j=y1; j<y2; j++) {
            nextMatrix[x1][j+1] = matrix[x1][j];
            minNum = min(minNum, matrix[x1][j]);
        }
        // ↓ 열(y2)은 같고 행++
        for (int j=x1; j<x2; j++) {
            nextMatrix[j+1][y2] = matrix[j][y2];
            minNum = min(minNum, matrix[j][y2]);
        }
        // ← 행(x2)은 같고 열--
        for (int j=y2; j>y1; j--) {
            nextMatrix[x2][j-1] = matrix[x2][j];
            minNum = min(minNum, matrix[x2][j]);
        }
        // ↑ 열(y1)은 같고 행--
        for (int j=x2; j>x1; j--) {
            nextMatrix[j-1][y1] = matrix[j][y1];
            minNum = min(minNum, matrix[j][y1]);
        }
        
        // 원본 벡터 업데이트
        copy(nextMatrix.begin(), nextMatrix.end(), matrix.begin());
        answer.push_back(minNum);
    }
    
    return answer;
}

int main() {
    int rows = 6;
    int columns = 6;

    vector<vector<int>> queries = {
        {2,2,5,4}, {3,3,6,6}, {5,1,6,3}
    };

    vector<int> answer = solution(rows, columns, queries);
    for (int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}