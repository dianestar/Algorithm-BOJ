#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isOutOfRange(int row, int col) {
    if (row < 0 || row >= 4 || col < 0 || col >= 4) {
        return true;
    }
    return false;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 2147483647;
    
    vector<int> cards; // 카드 번호를 담는 벡터
    unordered_map<int, vector<pair<int, int>>> cardPos; // cardPost[i]: i번 카드들의 행열 인덱스 리스트
    
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[0].size(); j++) {
            // 카드 번호가 0이 아닐 경우
            // cf. 0은 카드가 제거된 빈 칸을 의미
            if (board[i][j] != 0) {
                // 처음 발견된 카드 번호일 경우
                if (cardPos[board[i][j]].size() == 0) {
                    // cards 벡터에 push
                    cards.push_back(board[i][j]);
                }
                // 해당 카드의 행열 인덱스 저장
                cardPos[board[i][j]].push_back({i, j});
            }            
        }
    }
    // next_permutation 수행을 위해 오름차순 정렬
    sort(cards.begin(), cards.end());
    
    // 몇 번 카드부터 제거할 것인지 순열 구하기
    do {
        // 카드가 제거된 칸은 0으로 초기화할 것이므로 경우의 수마다 원본 board의 복사본 마련
        vector<vector<int>> tempBoard(4, vector<int>(4));
        copy(board.begin(), board.end(), tempBoard.begin());
        
        // row: 움직이기 시작하는 행, col: 움직이기 시작하는 열
        int row = r;
        int col = c;
        
        // count: 이번 경우의 수에 필요한 키 조작 횟수
        int count = 0;
        
        // cards 순서대로 순회
        for (int i=0; i<cards.size(); i++) {
            // curNum: 현재 찾아야 하는 타겟 카드 번호
            int curNum = cards[i];
            
            // curNum에 해당하는 카드 두 개를 연속적으로 찾아야 함
            for (int j=0; j<2; j++) {
                // bfs
                queue<pair<pair<int, int>, int>> q;
                vector<vector<int>> visited(4, vector<int>(4, 0));
                q.push({{row, col}, 0});
                visited[row][col] = 1;
                
                while (!q.empty()) {
                    pair<int, int> curIdx = q.front().first;
                    int curCount = q.front().second;
                    q.pop();
                    
                    // 타겟 카드를 찾은 경우
                    if (tempBoard[curIdx.first][curIdx.second] == curNum) {
                        // 제거된 카드임을 표시하기 위해 tempBoard의 해당 위치를 0으로 초기화
                        tempBoard[curIdx.first][curIdx.second] = 0;
                        // 다음 탐색을 시작할 행열 위치를 방금 제거한 카드의 위치로 업데이트
                        row = curIdx.first;
                        col = curIdx.second;
                        // cf. 카드를 뒤집기 위해서는 [Enter] 키를 입력하며 [Enter] 키를 누르는 동작은 조작 횟수 1로 계산
                        count += curCount + 1;
                        break;
                    }
                    
                    for (int k=0; k<4; k++) {
                        // 방향키 중 하나를 누르는 경우
                        // cf. 방향키 중 하나를 누르면 커서가 누른 키 방향으로 1칸 이동하며, 방향키를 누르는 동작은 조작 횟수 1로 계산
                        int adjRow = curIdx.first + dr[k];
                        int adjCol = curIdx.second + dc[k];
                        
                        if (!isOutOfRange(adjRow, adjCol) && !visited[adjRow][adjCol]) { 
                            q.push({{adjRow, adjCol}, curCount+1});
                            visited[adjRow][adjCol] = 1;
                        }
                        
                        // Ctrl + 방향키를 누르는 경우
                        // cf. Ctrl + 방향키를 누르면 누른 키 방향에 있는 가장 가까운 카드 혹은 그 방향의 가장 마지막 칸으로 이동하며, Ctrl + 방향키를 누르는 동작은 조작횟수 1로 계산
                        int farRow = curIdx.first;
                        int farCol = curIdx.second;
                        
                        while (!isOutOfRange(farRow + dr[k], farCol + dc[k])) {
                            farRow += dr[k];
                            farCol += dc[k];
                            if (tempBoard[farRow][farCol]) {
                                break;
                            }
                        }
                        if (!visited[farRow][farCol]) {
                            q.push({{farRow, farCol}, curCount+1});
                            visited[farRow][farCol] = 1;
                        }
                    }
                }
            }
        }
        
        // answer: 모든 카드를 제거하기 위한 키 조작 횟수의 최솟값
        // 이번 경우의 수의 키 조작 횟수와 비교하여 answer 값 업데이트
        if (count < answer) { answer = count; }
    } while (next_permutation(cards.begin(), cards.end()));
    
    return answer;
}

int main() {
    /*
    vector<vector<int>> board = {{1,0,0,3}, {2,0,0,0}, {0,0,0,2}, {3,0,1,0}};
    int r = 1;
    int c = 0;
    */

    vector<vector<int>> board = {{3,0,0,2}, {0,0,1,0}, {0,1,0,0}, {2,0,0,3}};
    int r = 0;
    int c = 1; 

    printf("%d\n", solution(board, r, c));

    return 0;
}