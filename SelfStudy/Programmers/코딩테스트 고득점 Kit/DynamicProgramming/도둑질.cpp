#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    
    /*
    Dynamic Programming 활용
    dp1[i] 또는 dp2[i]
    : 첫 번째 집을 털 경우 또는 털지 않을 경우 i+1번째 집까지 털 수 있는 돈의 최댓값
    */
    
    vector<int> dp1(N, 0); 
    dp1[0] = money[0]; // 첫 번째 집을 털 경우
    dp1[1] = dp1[0]; // 두 번째 집을 털 수 없음
    for (int i=2; i<N-1; i++) { // N번째 집 또한 첫 번째 집과 인접하여 털 수 없음
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    vector<int> dp2(N, 0);
    dp2[0] = 0; // 첫 번째 집을 털지 않을 경우
    dp2[1] = money[1]; // 두 번째 집을 털 수 있음
    for (int i=2; i<N; i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    answer = max(dp1[N-2], dp2[N-1]);
    
    return answer;
}

int main() {
    vector<int> money = {1,2,3,1};
    printf("%d", solution(money));

    return 0;
}