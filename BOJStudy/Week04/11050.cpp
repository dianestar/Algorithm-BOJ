#include <iostream>
using namespace std;

int factorial[11];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    factorial[0] = 1;
    factorial[1] = 1;
    for (int i=2; i<=10; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    printf("%d", factorial[N] / (factorial[N-K] * factorial[K]));

    return 0;
}