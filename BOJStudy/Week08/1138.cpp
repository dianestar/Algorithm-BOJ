#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> condition(N+1);
    for (int i=1; i<=N; i++) {
        scanf("%d", &condition[i]);
    }

    vector<int> sequence;
    for (int i=1; i<=N; i++) {
        sequence.push_back(i);
    }

    do {
        bool isValid = true;
        for (int i=0; i<N; i++) {
            int count = 0;
            for (int j=i; j>=0; j--) {
                if (sequence[j] > sequence[i]) { count++; }
            }
            if (count != condition[sequence[i]]) {
                isValid = false;
                break;
            }
        }
        if (isValid) { break; }
    } while (next_permutation(sequence.begin(), sequence.end()));

    for (int i=0; i<N; i++) {
        printf("%d ", sequence[i]);
    }

    return 0;
}