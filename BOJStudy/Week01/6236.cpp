#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<int> dailyMoney;
    int money;
    int minMoney = 1;
    int maxMoney = 0;
    for (int i=0; i<N; i++) {
        scanf("%d", &money);
        dailyMoney.push_back(money);
        if (money > minMoney) { minMoney = money; }
        maxMoney += money;
    }

    int answer;
    while (minMoney <= maxMoney) {
        int K = (minMoney + maxMoney) / 2;

        int curMoney = 0;
        int count = 0;
        for (int i=0; i<N; i++) {
            if (curMoney < dailyMoney[i]) {
                count++;
                curMoney = K;
            }
            curMoney -= dailyMoney[i];
        }

        if (count <= M) {
            maxMoney = K-1;
            answer  = K;
        }
        else {
            minMoney = K+1;
        }
    }

    printf("%d", answer);

    return 0;
}