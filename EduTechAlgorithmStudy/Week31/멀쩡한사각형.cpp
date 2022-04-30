#include <iostream>
#include <algorithm>
using namespace std;

int getGCD(int a, int b) { // assume a>b
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long gcd = getGCD(max(w,h), min(w,h));    
    long long longW = w;
    long long longH = h;
    answer = longW * longH - (longW + longH - gcd);
    
    return answer;
}

int main() {
    int w = 8;
    int h = 12;
    
    printf("%d", solution(w, h));

    return 0;
}