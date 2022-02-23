#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    /* cf) 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다.
    이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다. */
    for (int i=0; i<reserve.size(); i++) {
        auto lostIter = find(lost.begin(), lost.end(), reserve[i]);
        if (lostIter != lost.end()) {
            reserve.erase(reserve.begin()+i); // 체육복을 빌려줄 수는 없지만
            lost.erase(lostIter); // 체육수업을 들을 수는 있음
            i--;
        }
    }

    int lostN = lost.size();
    answer += n-lostN;

    /* 총 2회 탐색
    1회차 탐색 시에는 체육복을 1명에게만 빌릴 수 있는 학생들에게 우선적으로 체육복을 빌려줌 */
    int turn = 0;
    while (turn < 2) {
        for (int i=0; i<lostN; i++) {
            auto left = find(reserve.begin(), reserve.end(), lost[i]-1);
            auto right = find(reserve.begin(), reserve.end(), lost[i]+1);
            if (left == reserve.end() && right == reserve.end()) { // 체육복을 빌릴 수 없는 경우
                continue;
            }
            if (turn == 0 && left != reserve.end() && right != reserve.end()) { // 1회차 탐색 + 체육복을 2명에게 빌릴 수 있는 경우
                continue;
            }
            else if (left != reserve.end()) { // 앞번호의 학생에게 빌릴 수 있는 경우
                reserve.erase(left);
                answer++;
            }
            else { // 뒷번호의 학생에게 빌릴 수 있는 경우
                reserve.erase(right);
                answer++;
            }
        }
        turn++;
    }
    
    return answer;
}

int main() {
    vector<int> n = { 5, 5, 3, 5, 10 };
    vector<vector<int>> lost = {{2,4}, {2,4}, {3}, {2,3,4}, {5,4,3,2,1}};
    vector<vector<int>> reserve = {{1,3,5}, {3}, {1}, {3,4,5}, {3,1,2,5,4}};

    for (int i=0; i<n.size(); i++) {
        printf("%d\n", solution(n[i], lost[i], reserve[i]));
    }
}