#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_N 101
int N, M;
vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, INT_MAX));

int main() {
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (c < dist[a][b]) dist[a][b] = c;
	}

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] == INT_MAX ? printf("0 ") : printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}