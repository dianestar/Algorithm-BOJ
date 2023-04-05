#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

#define MAX_N 1001

int n, m, from, to;
vector<vector<int>> cost(MAX_N, vector<int>(MAX_N, INT_MAX));
vector<long long> minCost(MAX_N, INT_MAX);
vector<int> route(MAX_N);

int main() {
    scanf("%d %d", &n, &m);

    int a, b, c;
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c < cost[a][b]) cost[a][b] = c;
    }

    scanf("%d %d", &from, &to);

    // dijkstra
    priority_queue<pair<long long, int>> pq;
    minCost[from] = 0;
    pq.push({0, from});

    while (!pq.empty()) {
        long long currCost = -pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (minCost[currNode] < currCost) continue;
        for (int i=1; i<=n; i++) {
            if (cost[currNode][i] != INT_MAX) {
                int nextNode = i;
                long long nextCost = currCost + cost[currNode][i];

                if (nextCost < minCost[nextNode]) {
                    route[nextNode] = currNode;
                    minCost[nextNode] = nextCost;
                    pq.push({-nextCost, nextNode});
                }
            }
        }
    }

    // 1. 출발 도시에서 도착 도시까지 가는데 드는 최소 비용 출력
    printf("%lld\n", minCost[to]);
    
    // 2. 그러한 최소 비용을 갖는 경로에 포함되어있는 도시의 개수 출력
    stack<int> s;
    int idx = to;
    while (idx != from) {
        s.push(idx);
        idx = route[idx];
    }
    s.push(idx);

    printf("%d\n", s.size());
    
    // 3. 최소 비용을 갖는 경로를 방문하는 도시 순서대로 출력
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}