#include <iostream>

using namespace std;

#define MAX_N 90

// N은 90보다 작거나 같은 자연수
int N;
// 90번째 피보나치 수는 2880067194370816120으로 int 범위를 넘어감
long long fibo[MAX_N + 1];

int main() {
	scanf("%d", &N);

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	printf("%lld", fibo[N]);

	return 0;
}