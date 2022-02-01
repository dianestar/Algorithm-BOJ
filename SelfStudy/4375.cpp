#include <iostream>
using namespace std;

int main() {
    /*
    HINT) 모듈러 연산
    x mod n = (x mod n) mod n
    (a + b) mod n = (a mod n + b mod n) mod n
    Line #20의 연산을 포함하지 않으면 시간 초과 발생
    */
 
    int N;
    int digit;
    while (scanf("%d", &N) != EOF) {
        digit = 1;
        int num = 1;
        while(1) {
            if (num % N == 0) { break; }
            digit++;
            num = num * 10 + 1;
            num %= N;
        }
        printf("%d\n", digit);
    }
    
    return 0;
}