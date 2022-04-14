#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    vector<int> v;
    vector<long long> accumulatedSum(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        v.push_back(num);
        if (i == 0) { accumulatedSum[0] = num; }
        else { accumulatedSum[i] = accumulatedSum[i-1] + num; }
    }

    long long totalSum = 0;
    for (int i=0; i<N-1; i++) {
        totalSum += v[i] * (accumulatedSum[N-1] - accumulatedSum[i]);
    }

    printf("%lld", totalSum);

    return 0;
}