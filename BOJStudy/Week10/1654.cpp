#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    long long start = 1;
    long long end = 0;
    long long mid;
    int answer = 0;

    vector<int> having(K);
    for (int i=0; i<K; i++) {
        scanf("%d", &having[i]);
        if (having[i] > end) {
            end = having[i];
        }
    }

    while (start <= end) {
        mid = (start + end) / 2;

        int count = 0;
        for (int i=0; i<K; i++) {
            count += having[i] / mid;
        }
        if (count >= N) {
            start = mid + 1;
            if (mid > answer) { answer = mid; }
        }
        else {
            end = mid - 1;
        }
    }

    printf("%d", answer);

    return 0;
}