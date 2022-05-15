#include <iostream>
using namespace std;

long long power(long long a, long long b, long long c) {
    // (A*B) % C = ((A%C) * (B%C)) % C
    if (b == 0) { return 1; }
    else if (b == 1) { return a; }
    if (b % 2) { return power(a, b-1, c)*a; }

    long long half = power(a, b/2, c);
    half %= c;
    return (half * half) % c;
}

int main() {
    long long A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld", power(A, B, C)%C);

    return 0;
}