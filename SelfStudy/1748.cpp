#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int answer = 0;

    // 입력
    int N;
    scanf("%d", &N);

    // N의 자릿수 구하기
    string S = to_string(N);
    int digit = S.size();

    // 1자리 수는 9개, 2자리 수는 90개, 3자리 수는 900개, ... i자리 수는 9 * pow(10, i-1)개
    for (int i=1; i<=digit; i++) {
        if (i == digit) {
            answer += i * (N - pow(10, i-1) + 1);
        }
        else {
            answer += i * 9 * pow(10, i-1);
        }
    }

    printf("%d", answer);

    return 0;
}
