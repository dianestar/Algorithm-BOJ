#include <iostream>
using namespace std;

#define MAX_NUM 1000001

int arr[MAX_NUM]; // arr[A]: f(A)의 값, 즉 A의 모든 약수를 더한 값
long long sum[MAX_NUM]; // sum[x]: g(x)의 값, 즉 x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값

int main() {
    for (int i=1; i<MAX_NUM; i++) {
        for (int j=1; i*j<MAX_NUM; j++) {
            arr[i*j] += i;
        }
    }
    
    sum[1] = arr[1];
    for (int i=2; i<MAX_NUM; i++) {
        sum[i] = sum[i-1] + arr[i];
    }

    int T;
    scanf("%d", &T);

    int N;
    for (int i=0; i<T; i++) {
        scanf("%d", &N);
        printf("%lld\n", sum[N]);
    }
    
    return 0;
}