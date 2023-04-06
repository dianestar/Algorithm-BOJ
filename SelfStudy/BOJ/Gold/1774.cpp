#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_N 1001

struct Edge {
    int from;
    int to;
    double dist;
};

struct Cmp {
    bool operator()(const Edge &a, const Edge &b) {
        return a.dist > b.dist;
    }
};

int N, M;
int cnt = 1;
double answer;
vector<pair<double, double>> coordinates(MAX_N);
vector<Edge> edges;
vector<int> parents(MAX_N);

int findRoot(int idx) {
    if (parents[idx] == idx) return idx;
    return parents[idx] = findRoot(parents[idx]);
}

void unionNodes(int from, int to, double dist) {
    from = findRoot(from);
    to = findRoot(to);

    if (from == to) return;

    parents[from] = to;
    answer += dist;
    cnt++;
}

int main() {   
    // input
    scanf("%d %d", &N, &M);

    double x, y;
    for (int i=1; i<=N; i++) {
        scanf("%lf %lf", &x, &y);
        coordinates[i] = {x, y};
    }

    // Kruskal's Algorithm - i) 이미 연결된 통로로 이어지는 노드들 체크
    for (int i=1; i<=N; i++) {
        parents[i] = i;
    }

    int s, e;
    for (int i=1; i<=M; i++) {
        scanf("%d %d", &s, &e);
        unionNodes(s, e, 0);
    }

    // 새로 만들어야 할 후보 통로들의 거리 계산
    for (int i=1; i<=N-1; i++) {
        for (int j=i+1; j<=N; j++) {
            if (findRoot(i) != findRoot(j)) {
                double dist = sqrt(pow(coordinates[i].first - coordinates[j].first, 2) + pow(coordinates[i].second - coordinates[j].second, 2));
                edges.push_back({i, j, dist});
            }
        }
    }

    // Kruskal's Algorithm - ii) 새로 만들어야 할 통로로 이어지는 노드들 체크
    priority_queue<Edge, vector<Edge>, Cmp> pq;
    for (int i=0; i<edges.size(); i++) {
        pq.push(edges[i]);
    }

    while (!pq.empty()) {
        if (cnt == N) break;
        
        Edge curr = pq.top();
        pq.pop();

        unionNodes(curr.from, curr.to, curr.dist);
    }

    // print (소수점 둘째자리까지 출력)
    printf("%.2lf", answer);

    return 0;
}