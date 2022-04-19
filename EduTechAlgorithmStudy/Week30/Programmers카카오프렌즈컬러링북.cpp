#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pixel {
    int color;
    int row;
    int col;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int m, int n, int row, int col) {
    if (row < 0 || row >= m || col < 0 || col >= n) {
        return true;
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (picture[i][j] && !visited[i][j]) {
                number_of_area++;
                
                queue<Pixel> q;
                q.push({picture[i][j], i, j});
                visited[i][j] = 1;
                int cur_size = 1;
                
                while (!q.empty()) {
                    Pixel curr = q.front();
                    q.pop();
                    
                    for (int k=0; k<4; k++) {
                        int nextRow = curr.row + dr[k];
                        int nextCol = curr.col + dc[k];
                        
                        if (isOutOfRange(m, n, nextRow, nextCol)) { continue; }
                        if (!visited[nextRow][nextCol] && picture[nextRow][nextCol] == curr.color)  {
                            q.push({picture[nextRow][nextCol], nextRow, nextCol});
                            visited[nextRow][nextCol] = 1;
                            cur_size++;
                        }
                    }
                }
                
                if (cur_size > max_size_of_one_area) { max_size_of_one_area = cur_size; }
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}

int main() {
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {{1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3}};

    vector<int> answer = solution(m, n, picture);
    printf("%d %d", answer[0], answer[1]);

    return 0;
}