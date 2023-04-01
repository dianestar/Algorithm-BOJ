#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N; // cf) 3 <= N <= 20
vector<vector<int>> like(401, vector<int>());
vector<pair<int, int>> seat(401, {-1, -1});
vector<vector<int>> map(21, vector<int>(21, -1));

// 위 오른쪽 아래 왼쪽
int dR[4] = {-1, 0, 1, 0};
int dC[4] = {0, 1, 0, -1};

/*
void printMap() {
    cout << "printMap" << endl;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    // cf) 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void selectSeat(int idx, vector<int> likeList) {
    vector<vector<int>> candidatesMap(21, vector<int>(21, 0)); // 후보 자리에 조건에 따라 점수를 매겨 점수가 가장 높은 자리로 선택
    vector<pair<int, int>> candidatesVec1; // 1번 조건에 따른 후보 자리의 행렬 인덱스를 담는 벡터
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (map[i][j] == -1) {
                candidatesVec1.push_back({i, j});
            }
        }
    }
    int maxScore = 0; // 후보 점수 중 최댓값

    // cf) 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    // idx번 학생이 좋아하는 학생 4명 자리에 대해 반복 
    for (int i=0; i<4; i++) {
        pair<int, int> likeSeat = seat[likeList[i]]; // 좋아하는 학생의 자리
        
        // 좋아하는 학생의 자리가 아직 미정일 경우 continue 
        if (likeSeat.first == -1) { continue; }

        // 좋아하는 학생의 자리의 인접한 칸 탐색
        for (int j=0; j<4; j++) {
            int row = likeSeat.first + dR[j];
            int col = likeSeat.second + dC[j];

            // 인접한 자리가 교실 범위 밖이거나 빈 자리가 아닐 경우 continue 
            if (row < 0 || row >= N || col < 0 || col >= N || map[row][col] != -1) { continue; }

            // 그 외 자리에 대해서 후보 점수 증가
            candidatesMap[row][col]++;

            // 해당 자리의 후보 점수가 maxScore보다 클 경우
            if (candidatesMap[row][col] > maxScore) {
                // 해당 점수로 maxScore 변경하고
                // candidatesVec1 비우고 해당 자리만 후보로 push
                maxScore = candidatesMap[row][col];
                candidatesVec1.clear();
                candidatesVec1.push_back({row, col});
            }
            // 해당 자리의 후보 점수가 maxScore과 같을 경우
            else if (candidatesMap[row][col] == maxScore) { 
                // candidatesVec1에 해당 자리도 후보로 push
                candidatesVec1.push_back({row, col});
            }
        }
    }

    // 1번 조건에 의해 결정
    if (candidatesVec1.size() == 1) { 
        seat[idx] = {candidatesVec1[0].first, candidatesVec1[0].second};
        map[candidatesVec1[0].first][candidatesVec1[0].second] = idx; 
    }
    
    // cf) 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
    else {
        vector<pair<int, int>> candidatesVec2(candidatesVec1); // 2번 조건에 따른 후보 자리의 행렬 인덱스를 담는 벡터
        
        // 1번 조건을 통해 필터링 된 후보 자리에 대해 반복 
        for (int i=0; i<candidatesVec1.size(); i++) {
            // 후보 자리
            int row = candidatesVec1[i].first;
            int col = candidatesVec1[i].second;

            // 후보 자리의 인접한 자리 탐색
            for (int j=0; j<4; j++) {
                int adjRow = row + dR[j];
                int adjCol = col + dC[j];

                // 인접한 자리가 범위 내에 있고 빈 자리일 경우 
                if (adjRow >= 0 && adjRow < N && adjCol >= 0 && adjCol < N && map[adjRow][adjCol] == -1) {
                    // 후보 자리에 대해서 후보 점수 증가
                    candidatesMap[row][col]++;

                    // 해당 자리의 후보 점수가 maxScore보다 클 경우
                    if (candidatesMap[row][col] > maxScore) {
                        // 해당 점수로 maxScore 변경하고
                        // candidatesVec2 비우고 해당 자리만 후보로 push
                        maxScore = candidatesMap[row][col];
                        candidatesVec2.clear();
                        candidatesVec2.push_back({row, col});
                    }
                    // 해당 자리의 후보 점수가 maxScore과 같을 경우
                    else if (candidatesMap[row][col] == maxScore) {    
                        // candidatesVec2에 해당 자리도 후보로 push
                        candidatesVec2.push_back({row, col});
                    }
                }
            }
        }

        // 2번 조건에 의해 결정
        if (candidatesVec2.size() == 1) { 
            seat[idx] = {candidatesVec2[0].first, candidatesVec2[0].second};
            map[candidatesVec2[0].first][candidatesVec2[0].second] = idx;
        }
        
        // 3번 조건에 의해 결정 (cmp 함수 참고)
        else { 
            sort(candidatesVec2.begin(), candidatesVec2.end(), cmp);
            seat[idx] = {candidatesVec2[0].first, candidatesVec2[0].second};
            map[candidatesVec2[0].first][candidatesVec2[0].second] = idx;
        }
    }

    // 자리 배치 종료 후 만족도를 구하기 위해 like 벡터에 likeList 저장
    like[idx] = likeList;
}

int satisfaction(int num) { // num은 학생의 수
    int answer = 0;
    for (int i=1; i<=num; i++) {
        int row = seat[i].first;
        int col = seat[i].second;

        // cf) 학생의 만족도를 구하려면 그 학생과 인접한 칸에 앉은 좋아하는 학생의 수를 구해야 한다. 
        int count = 0;
        for (int j=0; j<4; j++) {
            int adjRow = row + dR[j];
            int adjCol = col + dC[j];

            if (adjRow < 0 || adjRow >= N || adjCol < 0 || adjCol >= N) { continue; }
            if (find(like[i].begin(), like[i].end(), map[adjRow][adjCol]) != like[i].end()) { count++; }
        }

        // cf) 그 값이 0이면 학생의 만족도는 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000이다.
        if (count != 0) {
            answer += pow(10, count-1);
        }
    }

    return answer;
}

int main() {
    // 입력
    scanf("%d", &N);
    int num = N * N; // num은 학생의 수

    int idx;
    for (int i=0; i<num; i++) {
        scanf("%d", &idx);

        int likeIdx;
        vector<int> likeList;
        for (int i=0; i<4; i++) {
            scanf("%d", &likeIdx);
            likeList.push_back(likeIdx);
        }

        // 자리 배치
        selectSeat(idx, likeList);
    }

    // 만족도 구하기
    int answer = satisfaction(num);

    //출력
    printf("%d", answer);

    return 0;
}