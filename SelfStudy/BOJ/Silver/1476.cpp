#include <iostream>
using namespace std;

// solution #1)
/*
int yearToS(int year) { // 1<=S<=28
    while (year > 28) {
        year -= 28;
    }
    return year;
}

int yearToM(int year) { // 1<=M<=19
    while (year > 19) {
        year -= 19;
    }
    return year;
}
*/

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);

    // solution #1)
    /*
    int year = E;
    while (1) {
        if (yearToS(year) == S && yearToM(year) == M) {
            break;
        }
        year += 15; // 1<=E<=15
    }
    */

    int year = 1;
    while (1) {
        if ((year-E) % 15 == 0 && (year-S) % 28 == 0 && (year-M) % 19 == 0) {
            break;
        }
        year++;
    }

    printf("%d", year);

    return 0;
}