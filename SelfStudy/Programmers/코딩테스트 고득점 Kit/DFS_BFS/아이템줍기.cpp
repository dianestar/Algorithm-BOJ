#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX_POINT 101

struct Movement {
    int x;
    int y;
    int dist;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isOutOfRange(int x, int y) {
    if (x < 1 || x > 100 || y < 1 || y > 100) return true;
    return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    int N = rectangle.size();
    vector<vector<int>> filled(MAX_POINT, vector<int>(MAX_POINT, 0));

    for (int k=0; k<N; k++) {
        for (int l=0; l<4; l++) {
            rectangle[k][l] *= 2;
        }

        int lowerLeftX = rectangle[k][0];
        int lowerLeftY = rectangle[k][1];
        int upperRightX = rectangle[k][2];
        int upperRightY = rectangle[k][3];        
        
        for (int i=lowerLeftX+1; i<upperRightX; i++) {
            for (int j=lowerLeftY+1; j<upperRightY; j++) {
                filled[i][j] = 1;
            }
        }
    }
    
    vector<vector<int>> isAvailable(MAX_POINT, vector<int>(MAX_POINT, 0));
    for (int k=0; k<N; k++) {
        int lowerLeftX = rectangle[k][0];
        int lowerLeftY = rectangle[k][1];
        int upperRightX = rectangle[k][2];
        int upperRightY = rectangle[k][3];        
        
        for (int i=lowerLeftX; i<=upperRightX; i++) {
            if (!filled[i][lowerLeftY]) isAvailable[i][lowerLeftY] = 1;
            if (!filled[i][upperRightY]) isAvailable[i][upperRightY] = 1;
        }
        
        for (int i=lowerLeftY; i<=upperRightY; i++) {
            if (!filled[lowerLeftX][i]) isAvailable[lowerLeftX][i] = 1;
            if (!filled[upperRightX][i]) isAvailable[upperRightX][i] = 1;
        }
    }
    
    queue<Movement> q;
    vector<vector<int>> visited(MAX_POINT, vector<int>(MAX_POINT, 0));
    q.push({characterX, characterY, 0});
    visited[characterX][characterY] = 1;
    
    while (!q.empty()) {
        Movement curr = q.front();
        q.pop();

        if (curr.x == itemX && curr.y == itemY) {
            answer = curr.dist / 2;
            break;
        }
        
        for (int k=0; k<4; k++) {
            int nextX = curr.x + dx[k];
            int nextY = curr.y + dy[k];
            
            if (isOutOfRange(nextX, nextY)|| !isAvailable[nextX][nextY] || visited[nextX][nextY]) continue;
            q.push({nextX, nextY, curr.dist+1});
            visited[nextX][nextY] = 1;
        }
    }
    
    return answer;
}

int main() {
    vector<vector<int>> rectangle = {{1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
    int characterX = 1;
    int characterY = 3;
    int itemX = 7;
    int itemY = 8;

    printf("%d\n", solution(rectangle, characterX, characterY, itemX, itemY));

    return 0;
}