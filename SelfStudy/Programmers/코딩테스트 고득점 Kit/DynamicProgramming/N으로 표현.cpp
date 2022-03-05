#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int listN(int N, int digit) {
    int num = 0;
    for (int i=0; i<=digit; i++) {
        num += N * pow(10, i);
    }
    return num;
}

int solution(int N, int number) {
    // number와 N이 동일할 경우
    if (number == N) { return 1; }
    
    vector<unordered_set<int>> dp(8); // dp[i]: i+1개의 N으로 만들 수 있는 숫자    
    dp[0].insert(N); // N 하나 뿐
    for (int i=1; i<8; i++) {
        // 사칙연산 없이 N을 이어붙인 NN, NNN, ... 형태의 숫자 insert
        dp[i].insert(listN(N, i)); 
        
        // 사칙연산을 활용해 표현한 숫자 insert
        for (int j=0; j<i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i-j-1]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a * b);
                    if (a - b > 0) { dp[i].insert(a - b); }
                    if (a / b > 0) { dp[i].insert(a / b); }
                }
            }
        }
        
        // i+1개의 N으로 number를 표현할 수 있는 경우
        if (dp[i].find(number) != dp[i].end()) {
            return i + 1;
        }
    }

    // cf) 최솟값이 8보다 크면 -1을 return
    return -1;
}

int main() {
    vector<int> N = {5, 2};
    vector<int> number = {12, 11};

    for (int i=0; i<N.size(); i++) {
        printf("%d\n", solution(N[i], number[i]));
    }

    return 0;
}