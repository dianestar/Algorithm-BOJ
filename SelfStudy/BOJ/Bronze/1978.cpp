#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) { return false; }

    int endNum = (int)sqrt(num);
    for (int i=2; i<=endNum; i++) {
        if (num % i == 0) { return false; }
    }

    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    int answer = 0;
    int num;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        if (isPrime(num)) { answer++; }
    }

    printf("%d", answer);

    return 0;
}