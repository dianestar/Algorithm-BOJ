#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int reverseA = 0;
    int reverseB = 0;
    int digit = 100;
    for (int i=0; i<3; i++) {
        reverseA += A % 10 * digit;
        reverseB += B % 10 * digit;
        A /= 10;
        B /= 10;
        digit /= 10;
    }

    if (reverseA > reverseB) {
        printf("%d", reverseA);
    }
    else {
        printf("%d", reverseB);
    }

    return 0;
}