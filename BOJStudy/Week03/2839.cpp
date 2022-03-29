#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int answer;
    if (N % 5 % 3 == 0) {
        answer = N / 5 + N % 5 / 3;
    }
    else {
        int fiveCount = N / 5;
        int i;
        for (i=fiveCount-1; i>=0; i--) {
            int remainder = N - 5 * i;
            if (remainder % 3 == 0) {
                answer = i + remainder / 3;
                break;
            }
        }
        if (i == -1) {
            answer = -1;
        }
    }

    printf("%d", answer);

    return 0;
}