#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
using namespace std;

// 두 팀의 능력치 차이의 최솟값 minDiff
int minDiff = INT_MAX;
// skill[i][j]: Sij 값
vector<vector<int>> skill(20, vector<int>(20));

int getSkillSum(vector<int> team) {
    int teamSize = team.size();
    int skillSum = 0;
    for (int i=0; i<teamSize; i++) {
        for (int j=0; j<teamSize; j++) {
            if (i == j) { continue; }
            skillSum += skill[team[i]][team[j]];
        }
    }
    return skillSum;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &skill[i][j]);
        }
    }

    // next_permutation을 활용한 조합 구하기
    // cf) 두 팀의 인원수는 같지 않아도 되지만, 한 명 이상이어야 한다.
    // 1명 vs N-1명, 2명 vs N-2명, ... N이 짝수일 경우 N/2명 vs N/2명 또는 N이 홀수일 경우 N/2명 vs N/2+1명의 경우
    for (int i=1; i<=N/2; i++) { 
        vector<int> isSelected;
        for (int j=0; j<N-i; j++) { isSelected.push_back(0); }
        for (int j=0; j<i; j++) { isSelected.push_back(1); }

        do {
            // 임의로 두 팀에 각각 startTeam, linkTeam이라고 이름 붙이기
            vector<int> startTeam;
            vector<int> linkTeam;
            for (int j=0; j<N; j++) {
                if (isSelected[j]) { startTeam.push_back(j); }
                else { linkTeam.push_back(j); }
            }

            // 이번 경우의 두 팀의 능력치 차이 currDiff 
            int curDiff = abs(getSkillSum(startTeam)-getSkillSum(linkTeam));
            // minDiff 값 업데이트
            if (curDiff < minDiff) { minDiff = curDiff; }
        } while (next_permutation(isSelected.begin(), isSelected.end()));
    }

    printf("%d", minDiff);

    return 0;
}