/* factorial DP 활용 풀이 */

#include <iostream>
using namespace std;

int N, K, answer;
int factorial[11];

int main() {
	scanf("%d %d", &N, &K);

	// 이항 계수 n! / (n-k)! * k!
	factorial[0] = 1; // 0 <= K <= N 이므로 0 팩토리얼 값도 계산해줘야 함
	factorial[1] = 1;
	for (int i = 2; i <= 10; i++) {
		factorial[i] = i * factorial[i - 1];
	}

	answer = factorial[N] / (factorial[N - K] * factorial[K]);
	printf("%d", answer);

	return 0;
}