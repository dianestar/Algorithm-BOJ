#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) { return false; }
    int squareRoot = (int)sqrt(num);
    for (int i=2; i<=squareRoot; i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) { break; }

        int a, b;
        bool isWrong = true;
        for (a=3; a<N; a++) {
            if (!isPrime(a)) { continue; }
            else {
                b = N-a;
                if (!isPrime(b)) { continue; }
                else {
                    isWrong = false;
                    break;
                }
            }
        }

        if (isWrong) { printf("Goldbach's conjecture is wrong.\n"); }
        else { printf("%d = %d + %d\n", N, a, b); }
    }

    return 0;
}