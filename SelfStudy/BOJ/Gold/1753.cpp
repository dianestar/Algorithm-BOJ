#include <iostream>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

#define MAX_V 200001
#define MAX_INT 2147483647

int V, E, K;
vector<pair<int, int>> edges[MAX_V]; // edges[i]: { i에서 인접한 정점의 번호, 간선의 가중치 } 
vector<int> dist(MAX_V, MAX_INT);

struct Cmp {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		// 가중치에 따른 최소힙 (오름차순 정렬)
		return a.second > b.second;
	}
};

int main() {
	scanf("%d %d %d", &V, &E, &K);

	int u, v, w;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edges[u].push_back({ v, w });
	}

	// Dijkstra's Algorithm
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
	dist[K] = 0;
	pq.push({ K, 0 });

	while (!pq.empty()) {
		int idx = pq.top().first;
		int weight = pq.top().second;
		pq.pop();

		if (dist[idx] < weight) continue;

		for (int i = 0; i < edges[idx].size(); i++) {
			int adjIdx = edges[idx][i].first;
			int adjWeight = edges[idx][i].second;
			int newWeight = weight + adjWeight;

			if (newWeight < dist[adjIdx]) {
				dist[adjIdx] = newWeight;
				pq.push({ adjIdx, newWeight });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		dist[i] == MAX_INT ? printf("INF\n") : printf("%d\n", dist[i]);
	}

	return 0;
}