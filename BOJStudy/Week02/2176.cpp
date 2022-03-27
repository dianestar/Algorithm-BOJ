#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100001
#define S 1
#define T 2

// edges[i].first: 정점 i와 인접한 정점(edges[i].second)의 거리 값, edges[i].second: 정점 i와 인접한 정점의 번호
vector<vector<pair<int, int>>> edges(1001); 

// 정점 T에서 각 정점까지의 최단 거리
vector<int> dist(1001, INF); 

// dp[i]: 정점 i에서 T까지의 합리적인 이동경로의 개수
vector<int> dp(1001);

// Dijkstra Algorithm
void dijkstra(int startNode) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // {dist, node}
    minHeap.push({0, startNode}); 
    dist[startNode] = 0;
    dp[2] = 1;
    
    while (!minHeap.empty()) {
        int currDist = minHeap.top().first;
        int currNode = minHeap.top().second;
        minHeap.pop();

        for (int i=0; i<edges[currNode].size(); i++) {
            int nextDist = edges[currNode][i].first;
            int nextNode = edges[currNode][i].second;

            if (dist[nextNode] > currDist + nextDist) {
                dist[nextNode] = currDist + nextDist;
                minHeap.push({dist[nextNode], nextNode});
            }
        }
    }
}

// Dynamic Programming을 활용한 합리적인 이동경로 개수 세기
int countRational(int node) {
    if (dp[node] != 0) { return dp[node]; }
    if (node == 2) { return dp[node] = 1; }

    for (int i=0; i<edges[node].size(); i++) {
        int nextNode = edges[node][i].second;
        if (dist[nextNode] < dist[node]) {
            dp[node] += countRational(nextNode);
        }
    }
    return dp[node];
}

int main() {
    // cf) 합리적인 이동경로: 정점 S(1)에서 정점 T(2)로 이동할 때 정점 T에 가까워지며 이동하는 경우
    int N, M;
    scanf("%d %d", &N, &M);

    int A, B, C;
    for (int i=0; i<M; i++) {
        scanf("%d %d %d", &A , &B, &C);
        edges[A].push_back({C, B});
        edges[B].push_back({C, A});
    }

    dijkstra(T);

    printf("%d", countRational(S));

    return 0;
}