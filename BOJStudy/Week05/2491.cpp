#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> sequence(N);
    for (int i=0; i<N; i++) {
        scanf("%d", &sequence[i]);
    }

    int longestLen = 1;
    int increasingLen = 1; // non-decreasing
    int decreasingLen = 1; // non-increasing
    for (int i=1; i<N; i++) {
        if (sequence[i] >= sequence[i-1]) { increasingLen++; }
        else { increasingLen = 1; }
        
        if (sequence[i] <= sequence[i-1]) { decreasingLen++; }
        else { decreasingLen = 1; }

        longestLen = max({longestLen, increasingLen, decreasingLen});
    }

    printf("%d", longestLen);

    return 0;
}