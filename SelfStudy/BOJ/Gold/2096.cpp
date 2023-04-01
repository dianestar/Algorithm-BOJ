/* 메모리 초과 해결 코드 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100001
typedef pair<int, int> pii;

int N;
/* N개 행의 dp 정보를 다 갖고 있을 필요 없음
이전 행의 dp 정보만 갖고 있으면 되기 때문에
캐시 행렬의 행의 크기는 2면 충분함 */
vector<vector<pii>> dp(2, vector<pii>(3)); // { max, min }

int main() {
	scanf("%d", &N);

	int a, b, c;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a, &b, &c);

		/* 입력 값을 따로 저장하지 않고
		행 별로 입력 받자마자 바로 dp 배열에 반영 */
		if (i == 0) {
			dp[0][0] = { a, a };
			dp[0][1] = { b, b };
			dp[0][2] = { c, c };
		}
		else {
			int cur = i % 2;
			int prev = (i - 1) % 2;

			dp[cur][0].first = a + max(dp[prev][0].first, dp[prev][1].first);
			dp[cur][1].first = b + max(dp[prev][0].first, max(dp[prev][1].first, dp[prev][2].first));
			dp[cur][2].first = c + max(dp[prev][1].first, dp[prev][2].first);

			dp[cur][0].second = a + min(dp[prev][0].second, dp[prev][1].second);
			dp[cur][1].second = b + min(dp[prev][0].second, min(dp[prev][1].second, dp[prev][2].second));
			dp[cur][2].second = c + min(dp[prev][1].second, dp[prev][2].second);
		}
	}

	int idx = (N - 1) % 2;
	int maxNum = max(dp[idx][0].first, max(dp[idx][1].first, dp[idx][2].first));
	int minNum = min(dp[idx][0].second, min(dp[idx][1].second, dp[idx][2].second));

	printf("%d %d", maxNum, minNum);

	return 0;
}