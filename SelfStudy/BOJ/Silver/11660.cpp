#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1025

int N, M;
vector<vector<int>> matrix(MAX_N, vector<int>(MAX_N));
vector<vector<int>> sum(MAX_N, vector<int>(MAX_N));

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j<= N; j++) {
			scanf("%d", &matrix[i][j]);
			sum[i][j] += sum[i - 1][j] + matrix[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int ret = 0;
		for (int j = y1; j <= y2; j++) {
			ret += sum[x2][j] - sum[x1 - 1][j];
		}
		printf("%d\n", ret);
	}

	return 0;
}