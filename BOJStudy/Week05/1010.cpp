#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    int N, M;
    vector<long long> answers;
    for (int i=0; i<T; i++) {
        scanf("%d %d", &N, &M);

        // M Combination N 구하기
        long long answer = 1;
        int j = 1;
        for (int i=M; i>M-N; i--) {
            answer *= i;
            answer /= j++;
        }

        answers.push_back(answer);
    }

    for (int i=0; i<T; i++) {
        printf("%lld\n", answers[i]);
    }

    return 0;
}