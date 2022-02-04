#include <iostream>
using namespace std;

// 최대공약수 구하기
int gcd(int M, int N) {
    if (M < N) {
        int temp = M;
        M = N;
        N = temp;
    }

    while (N != 0) {
        int temp = M % N;
        M = N;
        N = temp;
    }

    return M;
}

// 최소공배수 구하기
int lcm(int M, int N) {
    return (M * N) / gcd(M, N);
}

int main() {
    int T;
    scanf("%d", &T);

    int M, N, x, y;
    for (int i=0; i<T; i++) {
        scanf("%d %d %d %d", &M, &N, &x, &y);

        // 카잉 달력의 마지막 해 구하기
        int lastK = lcm(M ,N);

        // <x:y>에 의해 표현되는 해(k) 구하기
        int k = x;
        while (1) {
            if (k > lastK) {
                k = -1;
                break;
            }
            if ((k-y) % N == 0) { break; }
            k += M;
        }
        printf("%d\n", k);
    }

    return 0;
}