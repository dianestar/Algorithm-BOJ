#include <iostream>
using namespace std;

void printBinary(long long num) {
    if (num < 1) { return; }
    int remainder = num % 2;
    printBinary(num / 2);
    printf("%d", remainder);
}

int main() {
    long long N; // 1 <= N <= 100,000,000,000,000
    scanf("%lld", &N);
    printBinary(N);
    return 0;
}