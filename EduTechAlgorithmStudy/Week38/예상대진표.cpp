#include <iostream>
#include <algorithm>
using namespace std;

int reNumbering(int number) {
    return number / 2 + (number % 2);
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (a != b) {
        answer++;
        a = reNumbering(a);
        b = reNumbering(b);
    }
    
    return answer;
}

int main() {
    int N = 8;
    int A = 4;
    int B = 7;

    printf("%d\n", solution(N, A, B));
    
    return 0;
}