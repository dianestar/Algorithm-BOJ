#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 501

int N;
vector<vector<int>> triangle(MAX_N, vector<int>(MAX_N));

int main() {
	scanf("%d", &N);

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &num);
			triangle[i][j] = num;
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) triangle[i][j] += triangle[i - 1][1];
			else if (j == i) triangle[i][j] += triangle[i - 1][j-1];
			else triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}

	sort(triangle[N].begin(), triangle[N].end(), greater<int>());

	printf("%d", triangle[N][0]);

	return 0;
}