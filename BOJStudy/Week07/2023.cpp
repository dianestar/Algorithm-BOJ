#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N;

bool isPrime(int num) {
    if (num < 2) { return false; }

    for (int i=2; i<=(int)sqrt(num); i++) {
        if (num % i == 0) { return false; }
    }

    return true;
}

void recursion(int num, int len) {
    if (len == N) { printf("%d\n", num); }

    for (int i=1; i<=9; i++) {
        if (isPrime(num*10 + i)) {
            recursion(num*10+i, len+1);
        }
    }
}

int main() {
    scanf("%d", &N);

    // 한 자리 수인 소수는 2, 3, 5, 7 뿐이므로
    // 신기한 소수는 항상 2, 3, 5, 7 중 하나로 시작해야 함
    recursion(2, 1);
    recursion(3, 1);
    recursion(5, 1);
    recursion(7, 1);

    return 0;
}