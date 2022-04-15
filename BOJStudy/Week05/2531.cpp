#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, d, k, c; // 접시의 수 N, 초밥의 가짓수 c, 연속해서 먹는 접시의 수 k, 쿠폰 번호 c
    scanf("%d %d %d %d", &N, &d, &k, &c);

    vector<int> dishes(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &dishes[i]);
    }

    // 슬라이딩 윈도우 활용
    int maxCount = 0;
    for (int i=0; i<N; i++) {
        vector<bool> sushiAte(d); // sushiAte[i]: true일 경우 i번 초밥을 이미 먹음, false일 경우 먹지 않음
        int alreadyAte = 0; // 윈도우 내에서 중복되는 번호의 초밥 개수
        int couponLeft = 1; // 1일 경우 쿠폰으로 다른 초밥을 먹어볼 수 있음, 0일 경우 이미 먹음

        for (int j=i; j<i+k; j++) { // 연속 k개 확인
            // 이미 먹어본 초밥일 경우
            if (sushiAte[dishes[j%N]]) { alreadyAte++; } 

            // 먹어보지 않은 초밥일 경우
            else { sushiAte[dishes[j%N]] = 1; }
        }
        // 쿠폰 번호의 초밥을 이미 먹어본 경우
        if (sushiAte[c]) { couponLeft = 0; }

        int count = k - alreadyAte + couponLeft; // 이번 윈도우에서 먹을 수 있는 초밥의 가짓수
        
        // 최대 가짓수 업데이트
        if (count > maxCount) { maxCount = count; }
    }
    
    printf("%d", maxCount); 
    
    return 0;
}
