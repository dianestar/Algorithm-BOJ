#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) { return a; }
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * b / gcd(a,b);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    printf("%d\n%d", gcd(N, M), lcm(N, M));

    return 0;
}