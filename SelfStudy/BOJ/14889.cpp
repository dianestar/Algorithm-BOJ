#include <iostream>
using namespace std;

int N;
int S[20][20];
int selected[20] = {0, };
int minDiff = 99999999;

void calculateSkill() {
    int skillA = 0; // A팀(selectTeam 함수에서 뽑힌 사람들로 구성)의 능력 치
    int skillB = 0; // B팀(나머지 사람들로 구성)의 능력치

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (selected[i] && selected[j]) {
                skillA += S[i][j];
            }
            else if (!selected[i] && !selected[j]) {
                skillB += S[i][j];
            }
        }
    }

    int diff = skillA >= skillB ? skillA - skillB : skillB - skillA;
    if (diff < minDiff) {
        minDiff = diff;
    }
}

// 두 팀으로 나누는 것이므로 한 팀을 다 뽑으면 다른 팀은 알아서 구성됨
void selectTeam(int count, int idx) { // count: 뽑힌 사람의 수, idx: 다음 탐색 시작 값
    if (count == N/2) { // N/2명으로 이루어진 팀이 나누어진 경우
        calculateSkill(); // 각 팀의 능력치 계산 후 능력치 차이의 최솟값 업데이트
    }

    for (int i=idx; i<N; i++) {
        selected[i] = true;
        selectTeam(count+1, i+1);
        selected[i] = false; // 복원
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    selectTeam(0, 0);

    printf("%d", minDiff);
    
    return 0;
}  