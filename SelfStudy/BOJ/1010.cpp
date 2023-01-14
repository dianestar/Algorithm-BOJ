#include <iostream>
using namespace std;

#define MAX_N 31

int T, M, N;
long long dp[MAX_N][MAX_N];

int main() {
	for (int i = 1; i < MAX_N; i++) {
		for (int j = 0; j <= i; j++) {
			// 파스칼의 삼각형 nCk = n-1Ck-1 + n-1Ck
			if (j == i || j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);
		printf("%lld\n", dp[M][N]);
	}

	return 0;
}