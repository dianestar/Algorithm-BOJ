#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1001

struct Edge {
	int aNode;
	int bNode;
	int cost;
};

int N, M, answer;
vector<Edge> edges;
vector<int> parent(MAX_N);

// Union-Find 활용을 위한 find 함수
int findRoot(int val) {
	if (parent[val] == val) return val;
	return parent[val] = findRoot(parent[val]);
}

// Union-Find 활용을 위한 union 함수
void join(int a, int b) {
	int aRoot = findRoot(a);
	int bRoot = findRoot(b);
	parent[bRoot] = aRoot;
}

// sort custom compare 함수
bool compare(const Edge &a, const Edge &b) {
	return a.cost < b.cost;
}

int main() {
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back({ a, b, c });
	}

	// Union-Find parent 배열 초기화
	for (int i = 1; i <= N; i++) parent[i] = i;

	// 비용 오름차순 정렬
	sort(edges.begin(), edges.end(), compare);

	// Kruskal's Algorithm을 활용하여 MST 구성
	for (int i = 0; i < M; i++) {
		if (findRoot(edges[i].aNode) == findRoot(edges[i].bNode)) continue;

		answer += edges[i].cost;
		join(edges[i].aNode, edges[i].bNode);
	}

	printf("%d", answer);

	return 0;
}