#include <iostream>
using namespace std;

// arr[i]: i를 1,2,3의 합으로 나타내는 방법의 수
int arr[12];

int main() {
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    // dynamic programming 활용
    for (int i=4; i<=11; i++) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    int T;
    scanf("%d", &T);

    int num;
    for (int i=0; i<T; i++) {
        scanf("%d", &num);
        printf("%d\n", arr[num]);
    }

    return 0;
}