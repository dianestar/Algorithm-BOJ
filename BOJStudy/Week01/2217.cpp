#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> weights;
    int w;
    for (int i=0; i<N; i++) {
        scanf("%d", &w);
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    int curW;
    int maxW = 0;
    for (int i=N-1; i>=0; i--) {
        curW = weights[i] * (N-i);
        if (curW > maxW) { maxW = curW; }
    }

    printf("%d", maxW);
    
    return 0;
}