#include <iostream>
#include <cmath>
using namespace std;

// solution #2) arr[i]: i가 소수일 경우는 0 그 외는 1
int arr[1000001];

// solution #1)
/*
bool isPrime(int num) {
    if (num <= 1) { return false; }
    int squareRoot = (int)sqrt(num);
    for (int i=2; i<=squareRoot; i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}
*/

int main() {
    // 입력
    int M, N;
    scanf("%d %d", &M, &N);

    // solution #1)
    /*
    for (int i=M; i<=N; i++) {
        if (isPrime(i)) { printf("%d\n", i); }
    }
    */

    // solution #2)    
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i=2; i<=N; i++) {
        for (int j=2; i*j<=N; j++) {
            int multiple = i*j;
            if (arr[multiple] == 0) { arr[multiple] = 1; }
        }
    }

    for (int i=M; i<=N; i++) {
        if (arr[i] == 0) { printf("%d\n", i); }
    }

    return 0;
}