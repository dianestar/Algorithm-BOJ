#include <iostream>
#include <vector>
using namespace std;

int N;
int maxBroken;
vector<pair<int, int>> eggs;

// eggs[i].first: durability, eggs[i].second: weight
void tryBreaking(int curr) {
    // 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
    if (curr == N) {
        int broken = 0;

        // 깨진 계란(내구도가 0 이하인 계란) 개수 카운트
        for (int i=0; i<N; i++) {
            if (eggs[i].first <= 0) { broken++; }
        }

        // 깨진 계란의 최대 개수 업데이트
        if (broken > maxBroken) { maxBroken = broken; }
        return;
    }

    // 손에 든 계란이 깨졌으면 치지 않고 넘어간다. 
    if (eggs[curr].first <= 0 ) { 
        tryBreaking(curr+1);
        return;
    }

    // 깨지지 않은 계란 존재 여부 체크
    bool eggsLeft = false; 
    // 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 
    for (int i=0; i<N; i++) {
        if (eggs[i].first <= 0 || i == curr) { continue; }

        // 깨지지 않은 계란이 있는 경우 계란 치기 진행
        eggsLeft = true;
        eggs[i].first -= eggs[curr].second;
        eggs[curr].first -= eggs[i].second;
        tryBreaking(curr+1);
        // 백트래킹을 위해 복원
        eggs[i].first += eggs[curr].second;
        eggs[curr].first += eggs[i].second;
    }
    // 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
    if (!eggsLeft) { tryBreaking(N); }
}

int main() {
    scanf("%d", &N);

    int durability, weight;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &durability, &weight);
        eggs.push_back({durability, weight});
    }

    tryBreaking(0);

    printf("%d", maxBroken);

    return 0;
}