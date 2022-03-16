#include <iostream>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    if (N <= K) {
        printf("0");
    }
    
    else {
        int bottleNeeds = 0;
        while (1) {
            int quotient = N + bottleNeeds;
            int remainder = 0;
            int minBottle = 0;
            while (quotient > 0) {
                remainder += quotient%2;
                minBottle = remainder + quotient/2;
                quotient /= 2;
            }
            if (minBottle <= K) {
                printf("%d", bottleNeeds);
                break;
            }
            bottleNeeds++;
        }
    }

    return 0;
}