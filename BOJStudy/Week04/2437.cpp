#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> weights(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &weights[i]);
    }

    sort(weights.begin(), weights.end());

    int maxNum = 0;
    for (int i=0; i<N; i++) {
        if (weights[i] > maxNum + 1) {
            break;
        }
        maxNum += weights[i];
    }

    printf("%d", maxNum+1);

    return 0;
}