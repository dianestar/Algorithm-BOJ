#include <iostream>
using namespace std;

#define MAX_N 1001
#define DIVIDER 10007

int N, K;
int dp[MAX_N][MAX_N];

int main() {
	scanf("%d %d", &N, &K);

	for (int i = 1; i < MAX_N; i++) {
		for (int j = 0; j <= i; j++) {
			// 파스칼의 삼각형 nCk = n-1Ck-1 + n-1Ck
			if (j == i || j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % DIVIDER;
		}
	}

	printf("%d", dp[N][K]);
	
	return 0;
}