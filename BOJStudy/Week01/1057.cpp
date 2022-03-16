#include <iostream>
#include <algorithm>
using namespace std;

int getNextNum(int num, int N) {
    // 만약 그 라운드의 참가자가 홀수명이라면, 마지막 번호를 가진 참가자는 다음 라운드로 자동 진출한다. 
    if (N % 2 && num == N) { num = N / 2 + 1; }

    // 현재 홀수 번호일 경우
    else if (num % 2) { num = num / 2 + 1; }

    // 현재 짝수 번호일 경우
    else if (num % 2 == 0) { num = num / 2; }

    return num;
}

int main() {
    int N, J, H;
    scanf("%d %d %d", &N, &J, &H);

    int round = 0;
    while (1) {
        round++;
        if (max(J, H) % 2 == 0 && max(J, H) - min(J, H) == 1) { break; }

        J = getNextNum(J, N);
        H = getNextNum(H, N);
        
        N = N % 2 ? N / 2 + 1 : N / 2;
    }

    printf("%d", round);

    return 0;
}