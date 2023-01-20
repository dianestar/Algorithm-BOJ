#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 1001
typedef pair<int, int> pii;

int N, M, answer;
vector<pii> adj[MAX_N];
int visited[MAX_N];

struct Cmp {
	bool operator()(const pii &a, const pii &b) {
		return a.second > b.second; // 비용에 따른 오름차순 (최소힙)
	}
};

int main() {
	scanf("%d %d", &N, &M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	// Prim's Algorithm을 활용하여 MST 구성
	priority_queue<pii, vector<pii>, Cmp> pq;
	pq.push({ 1, 0 });

	while (!pq.empty()) {
		pair<int, int> currNode = pq.top();
		pq.pop();

		if (visited[currNode.first]) continue;

		visited[currNode.first] = 1;
		answer += currNode.second;

		for (int i = 0; i < adj[currNode.first].size(); i++) {
			pair<int, int> nextNode = adj[currNode.first][i];
			pq.push({ nextNode.first, nextNode.second });
		}
	}

	printf("%d", answer);

	return 0;
}