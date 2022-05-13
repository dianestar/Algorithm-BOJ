#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int M = 0;
    double sum = 0;
    int number;
    for (int i=0; i<N; i++) {
        scanf("%d", &number);
        if (number > M) { M = number; }
        sum += number;
    }

    printf("%lf", sum/M/N*100);

    return 0;
}