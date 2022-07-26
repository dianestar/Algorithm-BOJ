#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // N(4 ≤ N ≤ 20, N은 짝수) 20C10 = 184756 -> 브루트포스!
    int N;
    scanf("%d", &N);

    vector<vector<int>> skill(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &skill[i][j]);
        }
    }

    // 0번 팀과 1번 팀으로 나눈다고 가정
    int minValue = 2147483647;
    vector<int> isSelected;
    for (int i=0; i<N/2; i++) { isSelected.push_back(0); }
    for (int j=0; j<N/2; j++) { isSelected.push_back(1); }

    do {
        // (0, 1, 2)가 0번 팀인 것과 (3, 4, 5)가 0번 팀인 것은 사실상 같은 경우!
        // ∴ 조합을 순서대로 절반만 탐색하면 됨!
        for (int k=0; k<N/2; k++) {
            // teamSkill[i]: i번 팀의 능력치
            vector<int> teamSkill(2, 0);
            for (int i=0; i<N; i++) {
                for (int j=i+1; j<N; j++) {
                    // i번 사람과 j번 사람이 같은 팀에 속했을 때
                    if (isSelected[i] == isSelected[j]) {
                        // 팀에 더해지는 능력치는 Sij와 Sji
                        teamSkill[isSelected[i]] += (skill[i][j] + skill[j][i]);
                    }
                }
            }
            // 두 팀의 능력치의 차이의 최솟값 구하기
            minValue = min(minValue, abs(teamSkill[0] - teamSkill[1]));
        }
    } while (next_permutation(isSelected.begin(), isSelected.end()));

    printf("%d", minValue);

    return 0;
}