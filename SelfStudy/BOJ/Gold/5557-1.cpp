#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 101
#define MAX_RANGE 21

int N;
long long totalCount;
vector<int> numbers;
vector<vector<long long>> dp(MAX_N, vector<long long>(MAX_RANGE));

long long calculation(int idx, int ans) {
	if (idx == N - 1) {
		if (ans == numbers[N - 1]) return 1;
		return 0;
	}

	if (dp[idx][ans]) return dp[idx][ans];

	int plus = ans + numbers[idx];
	int minus = ans - numbers[idx];

	// cf. 왼쪽부터 계산할 때, 중간에 나오는 수가 모두 0 이상 20 이하이어야 한다.
	if (plus >= 0 && plus <= 20) dp[idx][ans] += calculation(idx + 1, plus);
	if (minus >=0 && minus <= 20) dp[idx][ans] += calculation(idx + 1, minus);

	return dp[idx][ans];
}

int main() {
	scanf("%d", &N);

	int number;
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		numbers.push_back(number);
	}

	// 첫 번째 숫자는 빼기가 불가능하므로 첫 번째 숫자는 무조건 더하고 시작한다고 가정
	printf("%lld", calculation(1, numbers[0]));

	return 0;
}