#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 101
#define MAX_RANGE 21

int N;
vector<int> numbers;
vector<vector<long long>> dp(MAX_N, vector<long long>(MAX_RANGE, 0));

int main() {
	scanf("%d", &N);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	// dp[i][j]: i번째 위치 숫자까지 연산했을 때 결과값이 j인 경우의 수
	dp[0][numbers[0]] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= 20; j++) {
			// numbers[i]를 더하여 j가 되는 경우
			if (j - numbers[i] >= 0) dp[i][j] += dp[i - 1][j - numbers[i]];

			// numbers[i]를 빼서 j가 되는 경우
			if (j + numbers[i] <= 20) dp[i][j] += dp[i - 1][j + numbers[i]];
		}
	}

	printf("%lld", dp[N - 2][numbers[N - 1]]);

	return 0;
}