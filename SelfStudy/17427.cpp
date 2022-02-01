#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    long long answer = 0;
    for (int i=1; i<=N; i++) {
        answer += i*(N/i);
    }
    printf("%lld", answer);

    return 0;
}

/*
아래와 같이 문제에 제시된
"자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다.
x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다."
를 그대로 구현할 경우 시간 초과 발생

int f(int num) {
    int sum = 0;
    int squareRoot = (int)sqrt(num);
    for (int i=1; i<=squareRoot; i++) {
        if (num % i == 0) {
            sum += i;
            if (i*i != num) {
                sum += num / i;
            }
        }
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    int answer = 0;
    for (int i=1; i<=N; i++) {
        answer += f(i);
    }
    printf("%d", answer);

    return 0;
}
*/ 