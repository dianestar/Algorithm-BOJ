#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 501
#define MAX_INT 2147483647

struct Edge {
	int start;
	int end;
	int weight;
};

int N, M;
vector<Edge> edges;
vector<long long> dist(MAX_N, MAX_INT);
/* => worst case: N * M * 최소간선 = 500 * 6,000 * (-10,000) = -30,000,000,000
   => underflow 발생 가능하므로 int 아닌 long long으로 선언 */


int main() {
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({ a, b, c });
	}

	// Bellman-Ford Algorithm
	dist[1] = 0;
	bool isValid = true; // true: 음수 사이클이 존재하지 않음 vs false: 존재함

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			Edge edge = edges[j];

			if (dist[edge.start] == MAX_INT) continue;
			if (dist[edge.start] + edge.weight < dist[edge.end]) {
				if (i == N) {
					isValid = false;
					break;
				}
				dist[edge.end] = dist[edge.start] + edge.weight;
			}
		}

		if (!isValid) break;
	}

	if (!isValid) printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			dist[i] == MAX_INT ? printf("-1\n") :  printf("%lld\n", dist[i]);
		}
	}

	return 0;
}