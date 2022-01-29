#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int N;
vector<int> price;
vector<int> endTime; // index: startTime, value: endTime

void solution1(int currTime, int totalPrice) {
    for (int i=currTime; i<N; i++) {
        if (endTime[i] >= N) { continue; } // 퇴사하여 회사에 없기 때문에 상담 불가한 경우
        solution1(endTime[i]+1, totalPrice+price[i]);
    }

    if (totalPrice > answer) { answer = totalPrice; } // 백준이가 얻을 수 있는 최대 수익 구하기
}
 
/*
// dynamic programming을 활용하여 풀 수도 있음
// dp[i]: N-1일차~i일차까지의 최대 이익 (0 <= i < N)
void solution2() {
    vector<int> dp(price);
    dp.push_back(0);

    for (int i=N-1; i>=0; i--) {
        if (endTime[i] >= N) {
            dp[i] = dp[i+1];
        }
        else {
            dp[i] = max(dp[i+1], price[i]+dp[endTime[i]+1]);
        }
    }

    answer = dp[0];
}
*/

int main() {
    scanf("%d", &N);
    int T, P;
    for (int i=0; i<N; i++) {
        scanf("%d %d", &T, &P);
        endTime.push_back(i+T-1);
        price.push_back(P);
    }

    solution1(0, 0);
    //solution2();

    printf("%d", answer);

    return 0;
}