#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int num;
    int count = 0;
    int answer = 0;
    for (int i=0; i<N; i++) {
        scanf("%d", &num);
        
        if (num) { // 맞는 경우
            count++;
            answer += count;
        }
        else { // 틀린 경우
            count = 0;
        }
    }

    printf("%d", answer);

    return 0;
}