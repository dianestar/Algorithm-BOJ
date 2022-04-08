#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    // A 5분(300초) B 1분(60초) C 10초
    if (T % 10 != 0) {
        printf("-1");
        return 0;
    } 

    int A, B, C;
    A = T / 300;
    T %= 300;
    B = T / 60;
    T %= 60;
    C = T / 10;
    
    printf("%d %d %d", A, B, C);

    return 0;
}