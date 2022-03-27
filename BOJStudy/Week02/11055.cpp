#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    vector<int> numbers;
    vector<int> dp;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        numbers.push_back(num);
        dp.push_back(num);
    }

    for (int i=1; i<N; i++) {
        int maxDP = 0;
        for (int j=i-1; j>=0; j--) {
            if (numbers[j] < numbers[i] && dp[j] > maxDP) {
                maxDP = dp[j];
            }
        }
        dp[i] += maxDP;
    }
    
    int answer = 0;
    for (int i=0; i<N; i++) {
        answer = max(answer, dp[i]);
    }

    printf("%d", answer);

    return 0;
}