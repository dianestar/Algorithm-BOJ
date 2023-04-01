#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_IDX 1001

int n, m;
int matrix[MAX_IDX][MAX_IDX];
int answer;

int getMin(int a, int b, int c) {
	return min(a, min(b, c));
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &matrix[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (matrix[i][j] == 1) {
				matrix[i][j] = getMin(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]) + 1;
				answer = max(answer, matrix[i][j]);
			}
		}
	}

	printf("%d", answer * answer);

	return 0;
}