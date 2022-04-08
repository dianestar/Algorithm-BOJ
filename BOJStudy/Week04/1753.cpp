#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647

int V, E;
vector<vector<pair<int, int>>> weight(20001);
vector<int> minWeight(20001, INF);

void dijkstra(int start) {
    minWeight[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        int currW = curr.first;
        int currV = curr.second;
        pq.pop();

        for (int i=0; i<weight[currV].size(); i++) {
            int nextV = weight[currV][i].first;
            int nextW = currW + weight[currV][i].second;
            if (nextW < minWeight[nextV]) {
                minWeight[nextV] = nextW;
                pq.push({nextW, nextV});
            }
        }
    }
}

// Dijkstra
int main() {
    scanf("%d %d", &V, &E);

    int startV;
    scanf("%d", &startV);

    int u, v, w;
    for (int i=0; i<E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        weight[u].push_back({v, w});
    }

    dijkstra(startV);

    for (int i=1; i<=V; i++) {
        if (minWeight[i] == INF) {
            printf("INF\n");
        }
        else {
            printf("%d\n", minWeight[i]);
        }
    }

    return 0;
}