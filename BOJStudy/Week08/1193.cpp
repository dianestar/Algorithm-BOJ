#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int X;
    scanf("%d", &X);

    int i = 1;
    while (X > i) {
        X -= i;
        i++;
    }

    int upper = X;
    int lower = (i+1) - X;
    if (i % 2) { swap(upper, lower); }

    printf("%d/%d", upper, lower);

    return 0;
}