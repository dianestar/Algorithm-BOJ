#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 301

int N;
int stairs[MAX_N];
int dp[MAX_N];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &stairs[i]);
	}

	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	printf("%d", dp[N]);

	return 0;
}