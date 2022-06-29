#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >=  N || col < 0 || col >= N) {
        return true;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // 자물쇠는 N*N 열쇠는 M*M
    N = lock.size();
    M = key.size();
    
    // 자물쇠의 홈 개수 구하기
    int toFill = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (lock[i][j] == 0) { toFill++; }
        }
    }
    
    // 열쇠의 돌기 개수 구하기
    int keyCount = 0;
    for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++) {
            if (key[i][j]) { keyCount++; }
        }
    }
    
    if (keyCount < toFill) { return false; }
    
    // 회전
    for (int k=0; k<4; k++) {
        vector<vector<int>> newKey(M, vector<int>(M));
        vector<pair<int, int>> keyList;
        for (int i=0; i<M; i++) {
            for (int j=0; j<M; j++) {
                newKey[i][j] = key[M-1-j][i];
                // 열쇠의 돌기 부분 인덱스 저장
                if (newKey[i][j]) { keyList.push_back({i, j}); }
            }
        }
        // 다음 회전을 위해 key 벡터 업데이트 해두기
        key = newKey;
        
        // 이동
        for (int x=(-1)*M+1; x<N; x++) {
            for (int y=(-1)*M+1; y<N; y++) {
                bool isValid = true;
                int filled = 0;
                
                // 회전+이동한 열쇠 돌기들의 인덱스에 해당하는 자물쇠 위치의 돌기/홈 여부를 체크
                for (int z=0; z<keyCount; z++) {
                    int movedRow = keyList[z].first + x;
                    int movedCol = keyList[z].second + y;
                    
                    // 자물쇠 영역을 벗어난 부분에 있는 열쇠의 홈과 돌기는 자물쇠를 여는 데 영향을 주지 않음
                    if (isOutOfRange(movedRow, movedCol)) { continue; }
                    // 열쇠의 돌기와 자물쇠의 돌기가 만나서는 안됨
                    if (lock[movedRow][movedCol]) {
                        isValid = false;
                        break;
                    }
                    // 자물쇠 영역 내에서는 열쇠의 돌기 부분과 자물쇠의 홈 부분이 정확히 일치해야 함
                    filled++;
                }
                
                // 자물쇠의 모든 홈을 채워 비어있는 곳이 없어야 자물쇠를 열 수 있음
                if (isValid && filled == toFill) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<int>> key = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };

    vector<vector<int>> lock = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    printf("%d\n", solution(key, lock));

    return 0;
}