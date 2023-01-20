#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 32001

int N, M;
vector<int> indegree(MAX_N);
vector<vector<int>> adj(MAX_N, vector<int>());

int main() {
	scanf("%d %d", &N, &M);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		indegree[b]++;
		adj[a].push_back(b);
	}

	// 위상 정렬
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	while (!q.empty()) {
		int curIdx = q.front();
		q.pop();

		for (int i = 0; i < adj[curIdx].size(); i++) {
			int adjIdx = adj[curIdx][i];
			indegree[adjIdx]--;

			if (!indegree[adjIdx]) q.push(adjIdx);
		}

		printf("%d ", curIdx);
	}

	return 0;
}