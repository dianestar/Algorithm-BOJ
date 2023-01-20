#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_N 500

int N, r, c;
vector<pair<int, int>> matrix;
vector<vector<int>> dp(MAX_N, vector<int>(MAX_N, INT_MAX));

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r, &c);
		matrix.push_back({ r, c });
	}

	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}
	
	for (int gap = 1; gap < N; gap++) {
		for (int start = 0; start < N - gap; start++) {
			int end = start + gap;
			for (int k = start; k < end; k++) {
				dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + matrix[start].first * matrix[k].second * matrix[end].second);
			}
		}
	}

	printf("%d", dp[0][N - 1]);
	
	return 0;
}